

#include "SphereParent.h"

ASphereParent::ASphereParent()
{
	PrimaryActorTick.bCanEverTick = true;
}
void ASphereParent::BeginPlay()
{
	Super::BeginPlay();
	SphereSpawn();
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

void ASphereParent::SetRandomLocationAndRotation()
{
	//RandomLocation.X=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	//RandomLocation.Y=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation = GetActorLocation();
	RandomRotation = GetActorRotation();
}

void ASphereParent::SphereSpawn()
{
	SetRandomLocationAndRotation();
	GetWorld()->SpawnActor<ASphereParent>(ActorToSpawn,RandomLocation,RandomRotation);
}
