// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereParent.h"


// Sets default values
ASphereParent::ASphereParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASphereParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Moving();
}

void ASphereParent::Moving()
{
	if (!IsMovingUp)
	{
		float NewXLocation = GetActorLocation().X + MovingSpeed * 0.2;
		SetActorLocation(FVector(NewXLocation,GetActorLocation().Y,GetActorLocation().Z));
	}
	else
	{
		float NewZLocation = GetActorLocation().Z + MovingSpeed * 0.2;
		SetActorLocation(FVector(GetActorLocation().X,GetActorLocation().Y,NewZLocation));
	}

}
