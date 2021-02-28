// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "Engine/TriggerVolume.h"


#include "LampCpp.h"


#include "MyTriggerVolume.generated.h"


UCLASS()
class AMyTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	

public:

	//ALampCPP* Lamp;

	/*// Create a static mesh component
	UStaticMeshComponent* cubeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));

	// Load the Cube mesh
	UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;*/

	

	
	// constructor sets default values for this actor's properties
	AMyTriggerVolume();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Element)
		TArray<AActor*> FoundActors;
	
	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	
};