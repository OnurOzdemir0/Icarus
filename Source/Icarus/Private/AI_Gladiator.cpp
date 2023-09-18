#include "AI_Gladiator.h"
#include "BaseGladiator.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AAI_Gladiator::AAI_Gladiator()
{
	PrimaryActorTick.bCanEverTick = true;
	TimeSinceLastAction = 0.0f;
}

void AAI_Gladiator::BeginPlay()
{
	Super::BeginPlay();
	ControlledGladiator = Cast<ABaseGladiator>(GetPawn());
	ActionCooldown -= ControlledGladiator->Agility;
}

void AAI_Gladiator::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if(ControlledGladiator)
	{
		TimeSinceLastAction += DeltaSeconds;
		if (TimeSinceLastAction >= ActionCooldown)
		{
			ChooseNextAction();
			TimeSinceLastAction = 0.0f;
			Round++;
		}
	}
}

void AAI_Gladiator::ChooseNextAction()
{
	
	if(ControlledGladiator)
	{
		if (ControlledGladiator->Malfunction)
		{
			ControlledGladiator->Malfunction = false;
			ControlledGladiator->stringAction = "Malfunction!";
			return;
		}
			
		Action = FMath::RandRange(0, 2);
		if (Action<2)
		{
			ControlledGladiator->Attack();
		}
		else
		{
			int RandomDirection = FMath::RandBool() ? 1 : -1;  // right or left?
			float RandomSpeed = FMath::RandRange(100,200);
			ControlledGladiator->Move(RandomDirection, RandomSpeed);
		}
	}
}

