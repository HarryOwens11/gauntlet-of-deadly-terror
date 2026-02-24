// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/DeathTriggerComponent.h"
#include "GameFramework/Actor.h"
#include "RetractingSpikeObstacle.generated.h"

UCLASS()
class GAUNTLETDEADLYTERROR_API ARetractingSpikeObstacle : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SpikeMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Trigger, meta = (AllowPrivateAccess = "true"))
	UDeathTriggerComponent* DeathTrigger;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timing, meta = (AllowPrivateAccess = "true"))
	float UpTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timing, meta = (AllowPrivateAccess = "true"))
	float DownTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timing, meta = (AllowPrivateAccess = "true"))
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timing, meta = (AllowPrivateAccess = "true"))
	bool SpikesUp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timing, meta = (AllowPrivateAccess = "true"))
	bool AutoMove;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timing, meta = (AllowPrivateAccess = "true"))
	float MoveDistance;
	
public:	
	// Sets default values for this actor's properties
	ARetractingSpikeObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float Timer;
	bool Moving;
};
