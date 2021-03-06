// © Opaque Multimedia 2014

#pragma once

#include "GameFramework/Actor.h"
#include "Proc_Skyscraper.h"
#include "Skyscraper_Controller.generated.h"

UCLASS()
class K4UINTRODUCTION_API ASkyscraper_Controller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkyscraper_Controller();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	void generateTreeCoordinates(int i);

	float generateX(float oldUsedX);

	float generateY(float oldUsedY);

	bool isUsed(TArray<float> &oldArray, float numcheck);

	float distanceBetween(float inOne, float inTwo);

	bool isOneGreater(float one, float two);

private:

	TArray<float> oldX;

	TArray<float> oldY;

	float newX;

	float newY;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object One")
		TSubclassOf<AProc_Skyscraper> skyscraperOne;

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object Two")
		TSubclassOf<AProc_Skyscraper> skyscraperTwo;

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object Three")
		TSubclassOf<AProc_Skyscraper> skyscraperThree;

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object Four")
		TSubclassOf<AProc_Skyscraper> skyscraperFour;

	UPROPERTY(EditDefaultsOnly, Category = "Possible Object Five")
		TSubclassOf<AProc_Skyscraper> skyscraperFive;

	
};
