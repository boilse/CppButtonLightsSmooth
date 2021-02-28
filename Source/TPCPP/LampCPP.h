// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LampCPP.generated.h"

UCLASS()
class TPCPP_API ALampCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALampCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Sphere")
		UStaticMeshComponent* SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));

	UPROPERTY(VisibleAnywhere, Category = "Sphere Mesh")
		UStaticMesh* SphereMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")).Object;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class USphereComponent* LightSphere;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		float LightIntensity;

	UPROPERTY(VisibleAnywhere, Category = "RGB")
		float r;

	UPROPERTY(VisibleAnywhere, Category = "RGB")
		float g;

	UPROPERTY(VisibleAnywhere, Category = "RGB")
		float b;

	UPROPERTY(VisibleAnywhere, Category = "Flag")
		bool fl;

	UFUNCTION(BlueprintCallable, Category = "Light Switch")
		void ToggleLight();
};
