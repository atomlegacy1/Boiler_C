// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereParent.generated.h"


UCLASS()
class GAME_C_API ASphereParent : public AActor
{
	GENERATED_BODY()
	
public:	

	ASphereParent();
	virtual void Tick(float DeltaTime) override;
	void SphereSpawn();
	void SetRandomLocationAndRotation();
	void MovingDirectionChecker();
	
	void Moving();
	
private:
	
	UPROPERTY(EditAnywhere,Category = "Moving Setup")
	bool IsMovingUp = false;
	UPROPERTY(EditAnywhere,Category = "Moving setup")
	float MovingDistance = 50;
	UPROPERTY(EditAnywhere,Category = "Moving Setup")
	int MovingSpeed = 0;
	int MovingSpeedConst = 0.2;
	UPROPERTY(EditAnywhere,Category = "Spawn setup")
	int MaxSpawnRange = 0;
	UPROPERTY(EditAnywhere,Category = "Spawn setup")
	int MinSpawnRange = 0;

	UPROPERTY(EditAnywhere,Category = "Spawn setup",meta =(AllowPrivateAccess = "true"))
	TSubclassOf<ASphereParent> ActorToSpawn;
	
	FVector RandomLocation;
	FRotator RandomRotation;

	int SphereNumSpawn = 0;
	int SphereCount = 15;

	int SphereMovingCounter = 0;
	int SphereMovingLimit = 500;

	bool SphereBackwardMoving = false;
protected:
	virtual void BeginPlay() override;
};

//TODO Material change by sphere number and direction//
//TODO Sphere moving direction change//
