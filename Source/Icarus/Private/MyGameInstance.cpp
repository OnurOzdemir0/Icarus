// Fill out your copyright notice in the Description page of Project Settings.
#include "MyGameInstance.h"
#include "BaseGladiator.h"
#include "MyBlueprintFunctionLibrary.h"

UMyGameInstance::UMyGameInstance()
{

}

void UMyGameInstance::OnGladiatorDeath(ABaseGladiator* Gladiator)
{
	if(Gladiator)
	{
		if(Gladiator->ActorHasTag("player"))
		{
			Round = 1;
			Health = 20;
			Damage = 5;
			Ammo = 2;
			Agility = 0.8f;
			UpgradePoints = 10;
			return;
		}
		else
		{
			Round++;
			EnemyStats = UMyBlueprintFunctionLibrary::RandomEnemyStat(Round);
			UpgradePoints += 5;
			return;
		}
	}
	return;
}