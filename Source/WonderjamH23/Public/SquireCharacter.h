﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Throwable.h"
#include "GameFramework/Character.h"
#include "SquireCharacter.generated.h"

UCLASS()
class WONDERJAMH23_API ASquireCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASquireCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Throwable")
	UObject* PotionToThrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Throwable")
	int NumPotionLeft;

	UFUNCTION(BlueprintCallable, Category="Throwable")
	int GetNumPotionLeft() const;
	UFUNCTION(BlueprintCallable, Category="Throwable")
	void SetNumPotionLeft(int newValue);
};
