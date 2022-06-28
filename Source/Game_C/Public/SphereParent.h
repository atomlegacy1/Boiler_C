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
	
	void Moving();
	void SphereSpawn();
	void SetRandomLocationAndRotation();
	
private:
	UPROPERTY(EditAnywhere,Category = "Moving Setup")
	bool IsMovingUp = false;

	UPROPERTY(EditAnywhere,Category = "Moving Setup")
	int MovingSpeed = 0;

	UPROPERTY(EditAnywhere,Category = "Spawn setup")
	int MaxSpawnRange = 0;

	UPROPERTY(VisibleAnywhere,Category = "Spawn setup")
	int MinSpawnRange = 0;

	UPROPERTY(EditAnywhere,Category = "Spawn setup",meta =(AllowPrivateAccess = "true"))
	TSubclassOf<ASphereParent> ActorToSpawn;
	
	FVector RandomLocation;
	FRotator RandomRotation;

	int SphereCount = 15;

protected:
	virtual void BeginPlay() override;
};
