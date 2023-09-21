// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

FVector4 UMyBlueprintFunctionLibrary::RandomEnemyStat(int level)
{
	FVector4 AttributesArray;

	float HealthMultiplier = 1.0f + (level - 1) * 0.2f;
	float DamageMultiplier = 1.0f + (level - 1) * 0.15f;
	float AmmoMultiplier = 1.0f + (level - 1) * 0.1f;
	float AgilityMultiplier = 1.0f + (level - 1) * 0.05f;
	

	// Generate Health
	float Health = FMath::RandRange(10, 100);
	Health = FMath::RoundToFloat(Health / 10) * 10;
	Health *= HealthMultiplier;
	AttributesArray.X = Health;

	// Generate Damage
	float Damage = FMath::RandRange(5, 50);
	Damage = FMath::RoundToFloat(Damage / 5) * 5;
	Damage *= DamageMultiplier;
	AttributesArray.Y = Damage;

	// Generate Ammo
	float Ammo = FMath::RandRange(1, 4);
	Ammo = FMath::RoundToFloat(Ammo / 2) * 2;
	Ammo *= AmmoMultiplier;
	AttributesArray.Z = Ammo;

	// Generate Agility
	float Agility = FMath::FRandRange(0.4f, 1.4f);
	Agility = FMath::RoundToFloat(Agility / 0.2f) * 0.2f;
	Agility *= AgilityMultiplier;
	AttributesArray.W = Agility;

	return AttributesArray;

}
