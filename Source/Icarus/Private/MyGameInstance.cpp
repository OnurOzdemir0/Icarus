// Fill out your copyright notice in the Description page of Project Settings.
#include "MyGameInstance.h"
#include "BaseGladiator.h"
#include "MyBlueprintFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

UMyGameInstance::UMyGameInstance()
{
	// Create and attach the audio component to the root
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
}

void UMyGameInstance::PlayBackgroundMusic(USoundBase* Music)
{
	if (Music && AudioComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Setting Sound"));
		AudioComponent->SetSound(Music);
        
		UE_LOG(LogTemp, Warning, TEXT("Activating AudioComponent"));
		AudioComponent->Activate(true);

		UE_LOG(LogTemp, Warning, TEXT("Playing Music"));
		AudioComponent->Play();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Music or AudioComponent is null"));
	}
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