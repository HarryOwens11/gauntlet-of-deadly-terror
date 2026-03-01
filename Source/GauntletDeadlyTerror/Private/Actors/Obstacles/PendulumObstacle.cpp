// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Obstacles/PendulumObstacle.h"

#include "FrameTypes.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APendulumObstacle::APendulumObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(Root);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
	
	DeathTrigger = CreateDefaultSubobject<UDeathTriggerComponent>("DeathTrigger");
	DeathTrigger->SetupAttachment(Mesh);
	
	Speed = 1.f;
	Siner = 0.f;
}

// Called when the game starts or when spawned
void APendulumObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APendulumObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Siner += DeltaTime;
	
	FRotator Rotation = UKismetMathLibrary::RLerp(FRotator(0.f), FRotator(0.f, 0.f, 60.f),  sin(Siner * Speed), true);
	SetActorRotation(Rotation);
}

