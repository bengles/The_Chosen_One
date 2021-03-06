// © Opaque Multimedia 2014

#include "K4UIntroduction.h"
#include "Skyscraper_Controller.h"


// Sets default values
ASkyscraper_Controller::ASkyscraper_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	newX = 0.f;
	newY = 0.f;

	oldX.SetNum(100);
	oldY.SetNum(100);
}

// Called when the game starts or when spawned
void ASkyscraper_Controller::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 25; i++)
	{
		generateTreeCoordinates(i);

		const UWorld* world = GetWorld();

		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = Instigator;

			FVector newVec;
			newVec.Set(newX, newY, FMath::RandRange(-2000, 1000));

			int32 num = FMath::RandRange(0, 4);

			if (num == 0)
			{
				AActor* newActor = GetWorld()->SpawnActor<AProc_Skyscraper>(skyscraperOne, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 1)
			{
				AActor* newActor = GetWorld()->SpawnActor<AProc_Skyscraper>(skyscraperTwo, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 2)
			{
				AActor* newActor = GetWorld()->SpawnActor<AProc_Skyscraper>(skyscraperThree, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 3)
			{
				AActor* newActor = GetWorld()->SpawnActor<AProc_Skyscraper>(skyscraperFour, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else
			{
				AActor* newActor = GetWorld()->SpawnActor<AProc_Skyscraper>(skyscraperFive, newVec, FRotator::ZeroRotator, spawnParams);
			}
		}
	}
}

// Called every frame
void ASkyscraper_Controller::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASkyscraper_Controller::generateTreeCoordinates(int i)
{
	newX = generateX(newX);
	newY = generateY(newY);

	if ((newX > -2900.f && newX < 2900.f) && (newY > -2900.f && newY < 2900.f))
	{
		generateTreeCoordinates(i);
	}
	else
	{
		oldX[i] = newX;
		oldY[i] = newY;
	}
}

float ASkyscraper_Controller::generateX(float oldUsedX)
{
	float passBack = 0.f;

	passBack = FMath::RandRange(-20000, 20000);
	//passBack = passBack + oldUsedX;

	if (passBack < -20000.f || passBack > 20000.f)
	{
		passBack = generateX(oldUsedX);
	}

	if (!isUsed(oldX, passBack))
	{
		passBack = generateX(oldUsedX);
	}

	return passBack;
}

float ASkyscraper_Controller::generateY(float oldUsedY)
{
	float passBack = 0.f;

	passBack = FMath::RandRange(-20000, 20000);
	//passBack = passBack + oldUsedY;

	if (passBack < -20000.f || passBack > 20000.f)
	{
		passBack = generateY(oldUsedY);
	}

	if (!isUsed(oldY, passBack))
	{
		passBack = generateY(oldUsedY);
	}

	return passBack;
}

bool ASkyscraper_Controller::isUsed(TArray<float> &oldArray, float numcheck)
{
	bool flag = true;

	for (int32 i = 0; i < oldArray.Num(); i++)
	{
		if (distanceBetween(oldArray[i], numcheck) < 1000.f)
		{
			flag = false;
		}
	}

	return flag;
}

float ASkyscraper_Controller::distanceBetween(float inOne, float inTwo)
{
	float passback = 0.f;

	bool flag = isOneGreater(inOne, inTwo);

	if (flag == true)
	{
		passback = inOne - inTwo;
	}
	else
	{
		passback = inTwo - inOne;
	}

	return passback;
}

bool ASkyscraper_Controller::isOneGreater(float inOne, float inTwo)
{
	bool flag = true;

	if (inOne <= inTwo)
	{
		flag = false;
	}

	return flag;
}