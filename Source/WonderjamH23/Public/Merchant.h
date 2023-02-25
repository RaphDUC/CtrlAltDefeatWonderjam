// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "InteractibleInterface.h"
#include "GameFramework/Character.h"
#include "Merchant.generated.h"

UCLASS()
class WONDERJAMH23_API AMerchant : public ACharacter, public IInteractibleInterface, public IGameplayTagAssetInterface
{
public:

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	UPROPERTY(EditAnywhere, Category="GameplayTags")
	FGameplayTagContainer GameplayTagContainer;
	
	virtual void EnteringSelectionRange_Implementation(AActor* Interactor) override;
	virtual void ExitingSelectionRange_Implementation(AActor* Interactor) override;
	virtual void Focused_Implementation(AActor* Interactor) override;
	virtual void Unfocused_Implementation(AActor* Interactor) override;
	virtual void Interact_Implementation(AActor* Interactor) override;
private:
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMerchant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
