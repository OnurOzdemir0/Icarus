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
	AAI_Gladiator();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void ChooseNextAction();

	ABaseGladiator* ControlledGladiator;
	
	float TimeSinceLastAction;
	const float ActionCooldown = 1.0f;
};
