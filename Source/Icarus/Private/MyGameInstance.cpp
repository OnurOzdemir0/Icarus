// Fill out your copyright notice in the Description page of Project Settings.
#include "MyGameInstance.h"
#include "BaseGladiator.h"

UMyGameInstance::UMyGameInstance()
{
	//create a default player
	Player = NewObject<ABaseGladiator>();
	Player->Health = 50;
	Player->Damage = 10;
	Player->Ammo = 3;
	Player->Agility = 1;
}
