// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthyAssessment.h"
#include "EnemyPatrol.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
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
	//if (Player)
	//{
	//	SetFocus(Player);
	//	MoveToActor(Player);
	//}
	UpdateControlRotation(DeltaSeconds);
}

void AEnemyPatrolAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	AEnemyPatrol* owner = (AEnemyPatrol*)GetPawn();

	TArray<USkeletalMeshComponent*> Components;

	if (owner)
	{
		owner->GetComponents<USkeletalMeshComponent>(Components);

		if (Components.Num() > 0)
		{
			USkeletalMeshComponent* bodyMeshComponent = Components[0];

			if (bodyMeshComponent)
			{
				// Make AI ragdoll on collision
				bodyMeshComponent->SetSimulatePhysics(true);
				bodyMeshComponent->WakeAllRigidBodies();
			}
		}
	}
}