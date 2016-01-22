// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "StealthyAssessmentCharacter.h"
#include "EnemyPatrolAIController.generated.h"

/**
 * 
 */
UCLASS()
class STEALTHYASSESSMENT_API AEnemyPatrolAIController : public AAIController
{
	GENERATED_BODY()

		AEnemyPatrolAIController(const class FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

private:

	/** The current player */
	class AStealthyAssessmentCharacter* Player;
	
};
