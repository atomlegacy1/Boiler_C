// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SphereMovingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_C_API USphereMovingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USphereMovingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:

	UPROPERTY(EditAnywhere,Category = SphereSetup)
	int MovingSpeed = 0;

	UPROPERTY(EditAnywhere,Category = SphereSetup)
	bool IsMovingUp = false;

	void Moving();
};
