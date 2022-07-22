

#include "FirstPersonParret.h"


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




