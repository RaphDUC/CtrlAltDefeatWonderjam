// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "UObject/Object.h"
#include "InteractorComponent.generated.h"

/**
 * 
 */
class ASquireCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WONDERJAMH23_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractorComponent();

	UPROPERTY(EditAnywhere, Category="Interactor")
	float TraceRadius = 30.0f;

	UPROPERTY(EditAnywhere, Category="Interactor")
	float TraceLength = 1000;

	UPROPERTY(EditAnywhere, Category="Interactor")
	float AreaOfInterestRadius = 1000;

	UPROPERTY(EditAnywhere, Category="Interactor")
	UEnvQuery* FindInteractibleEQS;

	UPROPERTY(EditAnywhere, Category="Interactor", meta=(Units="Hz"))
	float UpdateFrequency = 10;

	UPROPERTY(EditAnywhere, Category="Debug")
	bool bEnableDebugDraw = false;

	UPROPERTY(EditAnywhere, Category="Debug")
	FColor DebugColor = FColor::Green;

	UFUNCTION(BlueprintCallable, Category="Interactor")
	void PrimaryInteract();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	virtual void BeginPlay() override;
	
	void FindInteractibleInArea();

	FTimerHandle SearchTimer;

	UPROPERTY()
	AActor* BestInteractible;

	UPROPERTY()
	TArray<AActor*> RelevantInteractibles;

	void HandleQueryResult(TSharedPtr<FEnvQueryResult> result);

	ASquireCharacter* Owner;
};
