// Fill out your copyright notice in the Description page of Project Settings.


#include "Merchant.h"

void AMerchant::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}

void AMerchant::EnteringSelectionRange_Implementation(AActor* Interactor)
{
	IInteractibleInterface::EnteringSelectionRange_Implementation(Interactor);
}

void AMerchant::ExitingSelectionRange_Implementation(AActor* Interactor)
{
	IInteractibleInterface::ExitingSelectionRange_Implementation(Interactor);
}

void AMerchant::Focused_Implementation(AActor* Interactor)
{
	IInteractibleInterface::Focused_Implementation(Interactor);
}

void AMerchant::Unfocused_Implementation(AActor* Interactor)
{
	IInteractibleInterface::Unfocused_Implementation(Interactor);
}

void AMerchant::Interact_Implementation(AActor* Interactor)
{
	IInteractibleInterface::Interact_Implementation(Interactor);
}

// Sets default values
AMerchant::AMerchant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMerchant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMerchant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMerchant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

