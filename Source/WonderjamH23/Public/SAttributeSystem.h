// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeSystem.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WONDERJAMH23_API USAttributeSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USAttributeSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attributes")
	float Health;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attributes")
	float MaxHealth;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attributes")
	float Money;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attributes")
	float Damage;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attributes")
	float Armor;

	UFUNCTION(BlueprintCallable, Category="Attributes")
	float GetHealth() const;
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetHealth(float newValue);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	float GetMaxHealth() const;
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetMaxHealth(float newValue);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	float GetMoney() const;
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetMoney(float newValue);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	float GetDamage() const;
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetDamage(float newValue);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	float GetArmor() const;
	UFUNCTION(BlueprintCallable, Category="Attributes")
	void SetArmor(float newValue);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	void GetDamaged(float UnmitigatedDamage);
	
	UFUNCTION(BlueprintCallable, Category="Attributes")
    void GetHealed(float HealAmount);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	void Die();

	UFUNCTION(BlueprintCallable)
	bool isAlive();
	
};
