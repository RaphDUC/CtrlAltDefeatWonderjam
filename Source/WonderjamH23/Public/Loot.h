// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "InteractibleInterface.h"
#include "NativeGameplayTags.h"
#include "GameFramework/Actor.h"
#include "Loot.generated.h"

UCLASS()
class WONDERJAMH23_API ALoot : public AActor, public IInteractibleInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALoot();

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	UPROPERTY(EditAnywhere, Category="GameplayTags")
	FGameplayTagContainer GameplayTagContainer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EnteringSelectionRange_Implementation(AActor* Interactor) override;
	virtual void ExitingSelectionRange_Implementation(AActor* Interactor) override;
	virtual void Focused_Implementation(AActor* Interactor) override;
	virtual void Unfocused_Implementation(AActor* Interactor) override;
	virtual void Interact_Implementation(AActor* Interactor) override;
};
