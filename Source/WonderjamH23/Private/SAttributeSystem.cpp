// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeSystem.h"

#include "AICharacter.h"


// Sets default values for this component's properties
USAttributeSystem::USAttributeSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USAttributeSystem::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	// ...
	
}

float USAttributeSystem::GetHealth() const
{
	return Health;
}

void USAttributeSystem::SetHealth(float newValue)
{
	Health = newValue;
}

float USAttributeSystem::GetMaxHealth() const
{
	return MaxHealth;
}

void USAttributeSystem::SetMaxHealth(float newValue)
{
	MaxHealth = newValue;
}

float USAttributeSystem::GetMoney() const
{
	return Money;
}

void USAttributeSystem::SetMoney(float newValue)
{
	Money = newValue;
}

float USAttributeSystem::GetDamage() const
{
	return Damage;
}

void USAttributeSystem::SetDamage(float newValue)
{
	Damage = newValue;
}

float USAttributeSystem::GetArmor() const
{
	return Armor;
}

void USAttributeSystem::SetArmor(float newValue)
{
	Armor = newValue;
}

void USAttributeSystem::GetDamaged(float UnmitigatedDamage)
{
	Health -= (UnmitigatedDamage-Armor);
	if(Health <= 0)
	{
		Die();
	}
}

void USAttributeSystem::GetHealed(float HealAmount)
{
	Health += HealAmount;
	if(Health > MaxHealth)
	{
		Health = MaxHealth;
	}
}

void USAttributeSystem::Die()
{
	if(auto actor = Cast<AAICharacter>(GetOwner()))
	{
		actor->OnDeath();
	}
	GetOwner()->Destroy();
}

bool USAttributeSystem::isAlive()
{
	return Health > 0;
}

