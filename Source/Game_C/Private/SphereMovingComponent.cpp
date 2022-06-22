// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereMovingComponent.h"

USphereMovingComponent::USphereMovingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}

void USphereMovingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	USphereMovingComponent::Moving();
	
}

void USphereMovingComponent::Moving()
{
	if (IsMovingUp)
	{
		return;
	}
}
