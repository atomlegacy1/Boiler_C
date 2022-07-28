

#include "SphereParent.h"

ASphereParent::ASphereParent()
{
	PrimaryActorTick.bCanEverTick = true;
}
void ASphereParent::BeginPlay()
{
	Super::BeginPlay();
	RandomSphereMovingLimitSet();
}

void ASphereParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovingDirectionChecker();
}

void ASphereParent::Moving()
{
	FVector NewLocation;
	if (!IsMovingUp)
	{
		if (SphereBackwardMoving)
		{
			NewLocation = GetActorLocation() + GetActorForwardVector() * MovingSpeed * 0.2;
		}
		else
		{
			NewLocation = GetActorLocation() - GetActorForwardVector() * MovingSpeed * 0.2;
		}
		SetActorLocation(NewLocation);
	}
	else
	{
		if (SphereBackwardMoving)
		{
			NewLocation = GetActorLocation()+ GetActorUpVector() * MovingSpeed * 0.2;
		}
		else
		{
			NewLocation = GetActorLocation()-GetActorUpVector() * MovingSpeed * 0.2;
		}
		SetActorLocation(NewLocation);
	}
}

void ASphereParent::SetRandomLocationAndRotation()
{
	RandomLocation.X=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation.Y=FMath::RandRange(MinSpawnRange, MaxSpawnRange);
	RandomLocation.Z=FMath::RandRange(600, 850); //<--
	RandomRotation.Roll= FMath::RandRange(MinRandomRotation, MaxRandomRotation);
	RandomRotation.Yaw= FMath::RandRange(MinRandomRotation, MaxRandomRotation);
	RandomRotation.Pitch= FMath::RandRange(MinRandomRotation, MaxRandomRotation);

	ActorLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	RandomLocation = RandomLocation + 80 + ActorLocation ;
}
bool ASphereParent::SphereSpawn()
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
	return IsMovingUp;
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

void ASphereParent::RandomSphereMovingLimitSet()
{
	SphereMovingLimit = FMath::RandRange(200, 550);
}
