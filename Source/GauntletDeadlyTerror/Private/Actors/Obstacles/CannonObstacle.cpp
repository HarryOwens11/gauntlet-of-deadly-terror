// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Obstacles/CannonObstacle.h"

#include "Actors/Obstacles/CannonballObstacle.h"

// Sets default values
ACannonObstacle::ACannonObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(Root);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
	
	ShootPos = CreateDefaultSubobject<USceneComponent>("ShootPosition");
	ShootPos->SetupAttachment(Root);
	
	ShotSpeed = 30.f;
	ShotCooldown = 5.f;
	ShotTimer = 0.f;
}

// Called when the game starts or when spawned
void ACannonObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACannonObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ShotTimer += DeltaTime;
	
	if (ShotTimer >= ShotCooldown)
	{
		ShotTimer = 0.f;
		ACannonballObstacle* Cannonball = GetWorld()->SpawnActor<ACannonballObstacle>(CannonballClass, ShootPos->GetComponentLocation(), ShootPos->GetComponentRotation());
		Cannonball->GetMesh()->AddForce(ShootPos->GetUpVector() * ShotSpeed * 100000.f);
	}
}

