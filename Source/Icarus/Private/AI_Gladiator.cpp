#include "AI_Gladiator.h"
#include "BaseGladiator.h"
#include "GameFramework/Actor.h"

// Constructor
AAI_Gladiator::AAI_Gladiator()
{
	PrimaryActorTick.bCanEverTick = true;
	TimeSinceLastAction = 0.0f;
}

// BeginPlay
void AAI_Gladiator::BeginPlay()
{
	Super::BeginPlay();
	ControlledGladiator = Cast<ABaseGladiator>(GetPawn());
}

// Tick
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
		}
	}
}

// ChooseNextAction
void AAI_Gladiator::ChooseNextAction()
{
	if(ControlledGladiator)
	{
		// Choose a random action
		int32 Action = FMath::RandRange(0, 1);

		// Perform the action
		if (Action == 0)
		{
			ControlledGladiator->Attack();
		}
		else
		{
			//calculate random direction, and speed
			float RandomDirection = FMath::RandRange(-1.f, 1.f);
			float RandomSpeed = FMath::RandRange(-1.f, 1.f);
			ControlledGladiator->Move(RandomDirection, RandomSpeed*10.f);
		}
	}
}
