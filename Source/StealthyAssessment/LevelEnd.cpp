// Fill out your copyright notice in the Description page of Project Settings.

#include "StealthyAssessment.h"
#include "LevelEnd.h"


// Sets default values
ALevelEnd::ALevelEnd()
{
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	Collision->InitCapsuleSize(50, 70);
	Collision->AttachTo(RootComponent);

	Rotator = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatorComponent"));
	Rotator->RotationRate.Yaw = 180;
	Rotator->RegisterComponent();

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelEnd::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelEnd::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

