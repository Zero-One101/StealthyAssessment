// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "LevelEnd.generated.h"

UCLASS()
class STEALTHYASSESSMENT_API ALevelEnd : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ALevelEnd();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/** Make the Actor rotate */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class URotatingMovementComponent* Rotator;

	/** Give the Actor a capsule for Collision */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Collision)
	class UCapsuleComponent* Collision;

};
