// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonParret.h"

#include "../../../Plugins/Developer/RiderLink/Source/RD/thirdparty/clsocket/src/ActiveSocket.h"


AFirstPersonParret::AFirstPersonParret()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFirstPersonParret::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFirstPersonParret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AFirstPersonParret::SetGetPlayerStartLocation()
{
	StartActorLocation = GetActorLocation();
	return StartActorLocation;
}




