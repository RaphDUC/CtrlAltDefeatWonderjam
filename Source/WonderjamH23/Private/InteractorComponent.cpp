// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractorComponent.h"

#include "InteractibleInterface.h"
#include "SquireCharacter.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "Kismet/GameplayStatics.h"

UInteractorComponent::UInteractorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractorComponent::PrimaryInteract()
{
	if (!ensureAlways(Owner)) return;

	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	TArray<FHitResult> HitResults;
	FCollisionShape Shape;
	Shape.SetSphere(TraceRadius);

	FVector Begin = Owner->GetActorLocation();

	FVector End = ((Begin + (Owner->GetActorForwardVector() * TraceLength)) - FVector(0, 0, 300));

	bool bHitFound = GetWorld()->SweepMultiByObjectType(HitResults, Begin, End, FQuat::Identity, ObjectQueryParams,
	                                                    Shape);

	if (bEnableDebugDraw)
	{
		DrawDebugLine(GetWorld(), Begin, End, DebugColor, false, 2.0f, 0, 2.0f);
	}

	if (!bHitFound) return;

	for (auto& Hit : HitResults)
	{
		auto* HitActor = Hit.GetActor();
		if (!HitActor) continue;

		if (!HitActor->Implements<UInteractibleInterface>()) continue;
		IInteractibleInterface::Execute_Interact(HitActor, Owner);

		if (bEnableDebugDraw)
		{
			DrawDebugSphere(GetWorld(), Hit.ImpactPoint, TraceRadius, 32, DebugColor, false, 2.0f, 0, 2.0f);
		}

		break;
	}
}

void UInteractorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(SearchTimer);
}

void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();

	//Setup the owner of the component
	Owner = Cast<ASquireCharacter>(GetOwner());
	checkf(Owner, TEXT("Owner is not a ASquireCharacter"));

	//We only check for interactible if
	//the pawn is the one we are controlling
	if (Owner->IsLocallyControlled())
	{
		FTimerDelegate Delegate;
		Delegate.BindUObject(this, &UInteractorComponent::FindInteractibleInArea);
		GetWorld()->GetTimerManager().SetTimer(SearchTimer, Delegate, 1 / UpdateFrequency, true);
	}
}

void UInteractorComponent::FindInteractibleInArea()
{
	auto InteractibleQueryRequest = FEnvQueryRequest(FindInteractibleEQS, Owner);
	InteractibleQueryRequest.SetFloatParam(FName("ActorsOfClass.SearchRadius"), AreaOfInterestRadius);
	InteractibleQueryRequest.Execute(EEnvQueryRunMode::AllMatching, this, &UInteractorComponent::HandleQueryResult);
}

void UInteractorComponent::HandleQueryResult(TSharedPtr<FEnvQueryResult> result)
{
	if (!result->IsSuccessful()) return;


	for (const auto& Interactible : RelevantInteractibles)
	{
		if (!Interactible->Implements<UInteractibleInterface>()) continue;
		IInteractibleInterface::Execute_ExitingSelectionRange(Interactible, Owner);
	}

	RelevantInteractibles.Empty();
	result->GetAllAsActors(RelevantInteractibles);
	for (const auto& Interactible : RelevantInteractibles)
	{
		if (!Interactible->Implements<UInteractibleInterface>()) continue;
		IInteractibleInterface::Execute_EnteringSelectionRange(Interactible, Owner);
	}

	int i = 0;
	bool BestInteractibleFound = false;
	if (BestInteractible != nullptr)
	{
		IInteractibleInterface::Execute_Unfocused(BestInteractible, GetOwner());
	}
	while (i < result->Items.Num() && !BestInteractibleFound)
	{
		auto* RelevantActor = result->GetItemAsActor(i);
		if (RelevantActor->Implements<UInteractibleInterface>())
		{
			BestInteractibleFound = true;
			BestInteractible = RelevantActor;
			IInteractibleInterface::Execute_Focused(BestInteractible, GetOwner());
		}
		++i;
	}
}
