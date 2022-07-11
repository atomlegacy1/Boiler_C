

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
	MovingDirectionChecker();
}

void ASphereParent::Moving()
{
	float NewLocation;
	if (!IsMovingUp)
	{
		if (SphereBackwardMoving)
		{
			NewLocation = GetActorLocation().X + MovingSpeed * 0.2;
		}
		else
		{
			NewLocation = GetActorLocation().X - MovingSpeed * 0.2;
		}
		SetActorLocation(FVector(NewLocation,GetActorLocation().Y,GetActorLocation().Z));
	}
	else
	{
		if (SphereBackwardMoving)
		{
			NewLocation = GetActorLocation().Z + MovingSpeed * 0.2;
		}
		else
		{
			NewLocation = GetActorLocation().Z - MovingSpeed * 0.2;
		}
		SetActorLocation(FVector(GetActorLocation().X,GetActorLocation().Y,NewLocation));
	}
}

void ASphereParent::SetRandomLocationAndRotation()
{
	RandomLocation.X=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation.Y=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation.Z=GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z+100;
	RandomRotation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();
}
void ASphereParent::SphereSpawn()
{
	for (int i = 0; i < SphereCount; i++)
	{
		SphereNumSpawn = FMath::RandRange(0,1);
		if (SphereNumSpawn == 1)
		{
			SetRandomLocationAndRotation();
			IsMovingUp = false;
			GetWorld()->SpawnActor<ASphereParent>(ActorToSpawn,RandomLocation,RandomRotation);
		}
		else
		{
			SetRandomLocationAndRotation();
			IsMovingUp = true;
			GetWorld()->SpawnActor<ASphereParent>(ActorToSpawn,RandomLocation,RandomRotation);
		}
	}
}

void ASphereParent::MovingDirectionChecker()
{
	if (SphereMovingCounter==SphereMovingLimit)
	{
		SphereMovingCounter=0;
		if (SphereBackwardMoving)
		{
			SphereBackwardMoving = false;
		}
		else
		{
			SphereBackwardMoving = true;
		}
	}
	SphereMovingCounter++;
	Moving();
}


