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
	// Set the player variable equal to the first player
	Player = (AStealthyAssessmentCharacter*) GetWorld()->GetFirstPlayerController();

	if (Player)
	{
		// Set the player as the current target
		SetFocus(Player);

		// Make the owning actor move towards the player
		MoveToActor(Player);
	}
}

void AEnemyPatrolAIController::Tick(float DeltaSeconds)
{
	// Rotate the owning actor to face the player
	UpdateControlRotation(DeltaSeconds);
}

void AEnemyPatrolAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	// Get the owning actor and cast it to an AEnemyPatrol pointer
	AEnemyPatrol* owner = (AEnemyPatrol*)GetPawn();

	TArray<USkeletalMeshComponent*> Components;

	if (owner)
	{
		// Get all USkeletalMeshComponents from the owning actor and store them in the TArray
		owner->GetComponents<USkeletalMeshComponent>(Components);

		if (Components.Num() > 0)
		{
			// AEnemyPatrol only has one USkeletalMeshComponent, so we can just cast the first element in the array
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