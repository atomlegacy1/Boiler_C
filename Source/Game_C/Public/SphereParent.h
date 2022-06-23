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
private:
	UPROPERTY(EditAnywhere,Category = "Moving Setup")
	bool IsMovingUp = false;

	UPROPERTY(EditAnywhere,Category = "Moving Setup")
	int MovingSpeed = 0;
	
};
