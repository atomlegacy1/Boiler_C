// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FirstPersonParret.generated.h"

UCLASS()
class GAME_C_API AFirstPersonParret : public AActor
{
	GENERATED_BODY()
	
public:	
	AFirstPersonParret();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	FVector SetGetPlayerStartLocation();
	void RandomSphereSpawn();

private:
	FVector StartActorLocation;

};
