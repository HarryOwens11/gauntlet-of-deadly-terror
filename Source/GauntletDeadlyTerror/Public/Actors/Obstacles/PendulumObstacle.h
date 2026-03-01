// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/DeathTriggerComponent.h"
#include "GameFramework/Actor.h"
#include "PendulumObstacle.generated.h"

UCLASS()
class GAUNTLETDEADLYTERROR_API APendulumObstacle : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Trigger, meta = (AllowPrivateAccess = "true"))
	UDeathTriggerComponent* DeathTrigger;
	
public:	
	// Sets default values for this actor's properties
	APendulumObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:	
	float Siner;

};
