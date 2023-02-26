// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Throwable.generated.h"

UCLASS()
class WONDERJAMH23_API AThrowable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AThrowable();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Throwable")
	float PotionStrength;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
