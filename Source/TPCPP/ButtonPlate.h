// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LampCpp.h"
#include "ButtonPlate.generated.h"

UCLASS()
class TPCPP_API AButtonPlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AButtonPlate();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Mesh
	UPROPERTY(VisibleAnywhere, Category = "Cube")
		UStaticMeshComponent* cubeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));

	//set mesh Cube
	UPROPERTY(VisibleAnywhere, Category = "Cube Mesh")
		UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;

	//Lights array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Element)
		TArray<AActor*> FoundActors;

	//Button press trigger
	UPROPERTY(VisibleAnywhere, Category = "Sphere Trigger")
		class USphereComponent* SphereTrigger;

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
