// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthyAssessment.h"
#include "StealthyAssessmentCharacter.h"
#include "EnemyPatrolAIController.h"

AEnemyPatrolAIController::AEnemyPatrolAIController(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void AEnemyPatrolAIController::Tick(float DeltaSeconds)
{
	class AStealthyAssessmentCharacter* Player;
}