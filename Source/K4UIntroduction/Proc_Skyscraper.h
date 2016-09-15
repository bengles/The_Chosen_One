// © Opaque Multimedia 2014

#pragma once

#include "GameFramework/Actor.h"
#include "Proc_Skyscraper.generated.h"

UCLASS()
class K4UINTRODUCTION_API AProc_Skyscraper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProc_Skyscraper();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
