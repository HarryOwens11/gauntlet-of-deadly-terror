// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Obstacles/RetractingSpikeObstacle.h"

// Sets default values
ARetractingSpikeObstacle::ARetractingSpikeObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(Root);
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	BaseMesh->SetupAttachment(Root);
	
	SpikeMesh = CreateDefaultSubobject<UStaticMeshComponent>("SpikeMesh");
	SpikeMesh->SetupAttachment(Root);
	
	DeathTrigger = CreateDefaultSubobject<UDeathTriggerComponent>("DeathTrigger");
	DeathTrigger->SetupAttachment(SpikeMesh);
	
	UpTime = 3.f;
	DownTime = 3.f;
	Speed = 200.f;
	
	SpikesUp = false;
	AutoMove = true;
	Moving = false;
	MoveDistance = 20.f;
}

// Called when the game starts or when spawned
void ARetractingSpikeObstacle::BeginPlay()
{
	Super::BeginPlay();
	
	Timer = SpikesUp ? UpTime : DownTime;
	if (SpikesUp)
	{
		SpikeMesh->AddRelativeLocation(FVector(0.0f, 0.0f, MoveDistance));
	}
}

// Called every frame
void ARetractingSpikeObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AutoMove && !Moving)
	{
		Timer -= DeltaTime;
		
		if (Timer <= 0.f)
		{
			Moving = true;
			SpikesUp = !SpikesUp;
			Timer = MoveDistance / Speed;
		}
	}
	
	if (Moving)
	{
		if (SpikesUp)
		{
			SpikeMesh->AddRelativeLocation(FVector(0.0f, 0.0f, Speed * DeltaTime));
		}
		else
		{
			SpikeMesh->AddRelativeLocation(FVector(0.0f, 0.0f, -Speed * DeltaTime));
		}
		
		Timer -= DeltaTime;
		
		if (Timer <= 0.f)
		{
			Moving = false;
			Timer = SpikesUp ? UpTime : DownTime;
		}
	}
}

