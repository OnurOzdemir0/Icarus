#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Gladiator.generated.h"

class ABaseGladiator;

UCLASS()
class ICARUS_API AAI_Gladiator : public AAIController
{
	GENERATED_BODY()
	
public:
	// Constructor
	AAI_Gladiator();

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Tick Override
	virtual void Tick(float DeltaSeconds) override;

	// Function to Choose Next Action
	void ChooseNextAction();



	// Reference to the Gladiator this AI is controlling
	ABaseGladiator* ControlledGladiator;

	// Time since the last action was performed
	float TimeSinceLastAction;

	// Cooldown time between actions
	const float ActionCooldown = .3f;
};
