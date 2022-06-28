

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
	//Moving();
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
	RandomLocation.X=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation.Y=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation.Z=GetActorLocation().Z;
	RandomRotation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();
}

void ASphereParent::SphereSpawn()
{
	for (int i = 0; i < SphereCount; i++)
	{
		SetRandomLocationAndRotation();
		GetWorld()->SpawnActor<ASphereParent>(ActorToSpawn,RandomLocation,RandomRotation);
	}
}
