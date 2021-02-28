// Fill out your copyright notice in the Description page of Project Settings.


#include "LampCPP.h"
#include "Components/PointLightComponent.h"


// Sets default values
ALampCPP::ALampCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set intensity
	LightIntensity = 3000.f;

	//Create Point Light
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("POint Light"));
	PointLight->Intensity = LightIntensity; 

	//Set root component
	RootComponent = PointLight;

	//set sphere mesh location and scale
	SphereMeshComponent->SetStaticMesh(SphereMesh);
	SphereMeshComponent->SetupAttachment(RootComponent);

	SphereMeshComponent->SetRelativeLocation(FVector(10, 0, 0));
	SphereMeshComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

}

// Called when the game starts or when spawned
void ALampCPP::BeginPlay()
{
	Super::BeginPlay();
	
	//Turn off lights
	PointLight->ToggleVisibility();

	//Set Switch flag = true
	fl = true;
}

// Called every frame
void ALampCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Change color smoothly
	if (fl) {
		if (r + 0.01 > 1) {
			if (g + 0.01 > 1) {
				if (b + 0.01 > 1) {
					fl = false;
				}
				else { b += 0.01; }
			}
			else { g += 0.01; }
		}
		else { r += 0.01; }
	}
	else {
		if (r - 0.01 < 0) {
			if (g - 0.01 < 0) {
				if (b - 0.01 < 0) {
					fl = true;
				}
				else { b -= 0.01; }
			}
			else { g -= 0.01; }
		}
		else { r -= 0.01; }
	}
	
	PointLight->SetLightColor(FLinearColor(1, b, g, r), true);
	
	}


//Turn on/off lights
void ALampCPP::ToggleLight()
{
	PointLight->ToggleVisibility();
}

