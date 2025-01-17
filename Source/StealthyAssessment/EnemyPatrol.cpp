// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthyAssessment.h"
#include "EnemyPatrol.h"


// Sets default values
AEnemyPatrol::AEnemyPatrol()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	// Allows the EnemyPatrolAIController to turn the Character
	GetCharacterMovement()->bUseControllerDesiredRotation = true;

}

// Called when the game starts or when spawned
void AEnemyPatrol::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPatrol::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AEnemyPatrol::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

