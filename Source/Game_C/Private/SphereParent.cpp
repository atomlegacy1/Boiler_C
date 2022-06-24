

#include "SphereParent.h"
#include "Kismet/GameplayStatics.h"

ASphereParent::ASphereParent()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ASphereParent::BeginPlay()
{
	Super::BeginPlay();
	SetRandomLocationAndRotation();
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

void ASphereParent::SphereSpawn()
{
	SpawnRange = 2000;
	PlayerCharacterLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	for	(int i =0; i<SphereCount; i++)
	{
		SetRandomLocationAndRotation();
		//GetWorld()->SpawnActor();
	}
}

void ASphereParent::SetRandomLocationAndRotation()
{
	RandomLocation.X=rand() % SpawnRange;
	RandomLocation.Y=rand() % SpawnRange;
	RandomRotation = GetActorRotation();
}
