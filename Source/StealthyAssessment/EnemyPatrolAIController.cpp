// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthyAssessment.h"
#include "EnemyPatrolAIController.h"

AEnemyPatrolAIController::AEnemyPatrolAIController(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void AEnemyPatrolAIController::BeginPlay()
{
	Player = (AStealthyAssessmentCharacter*) GetWorld()->GetFirstPlayerController();

	if (Player)
	{
		SetFocus(Player);
		MoveToActor(Player);
	}
}

void AEnemyPatrolAIController::Tick(float DeltaSeconds)
{
	if (Player)
	{
		SetFocus(Player);
		MoveToActor(Player);
	}
	UpdateControlRotation(DeltaSeconds);
}

void AEnemyPatrolAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{

}