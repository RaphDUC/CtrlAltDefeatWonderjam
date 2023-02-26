// Fill out your copyright notice in the Description page of Project Settings.


#include "SquireCharacter.h"


// Sets default values
ASquireCharacter::ASquireCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASquireCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASquireCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASquireCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

int ASquireCharacter::GetNumPotionLeft() const
{
	return NumPotionLeft;
}

void ASquireCharacter::SetNumPotionLeft(int newValue)
{
	NumPotionLeft = newValue;
}

