// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Obstacles/SpinningObstacle.h"

// Sets default values
ASpinningObstacle::ASpinningObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 100.0f;
}

// Called when the game starts or when spawned
void ASpinningObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpinningObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldRotation(FRotator(0.0f, Speed * DeltaTime, 0.0f));
}

