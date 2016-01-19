// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
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
	virtual void Tick(float DeltaSeconds) override;
	
};
