// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonPlate.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"


// Sets default values
AButtonPlate::AButtonPlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
 
    // Set the component's mesh and scale
    cubeMeshComponent->SetStaticMesh(cubeMesh);
    cubeMeshComponent->SetRelativeScale3D(FVector(1, 1, 0.25f));

    //Set trigger
    SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Trigger"));

    // Set as root component
    RootComponent = SphereTrigger;

   // RootComponent = SphereTrigger;
    cubeMeshComponent->SetupAttachment(RootComponent);
    
    //Set Overlap functions
	OnActorBeginOverlap.AddDynamic(this, &AButtonPlate::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AButtonPlate::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AButtonPlate::BeginPlay()
{
	Super::BeginPlay();
	
    //Get All Lights in the world
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALampCPP::StaticClass(), FoundActors);

}


// Called every frame
void AButtonPlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AButtonPlate::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && OtherActor != this)
    {
        //Debug
        /* if (GEngine)
         {
             GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
             GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));
         };*/

        //toggle on all lights
        for (int i = 0; i < FoundActors.Num(); i++)
        {
            ALampCPP* Lamp = Cast<ALampCPP>(FoundActors[i]);
            Lamp->ToggleLight();

        }

        //simulate button press (Visual)
        cubeMeshComponent->SetRelativeScale3D(FVector(1, 1, 0.1f));

    }
}

void AButtonPlate::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this)
    {
        //Debug
        /* if (GEngine)
         {
             GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
             GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Volume"), *OtherActor->GetName()));
         }*/

        //toggle off all lights
        for (int i = 0; i < FoundActors.Num(); i++)
        {
            ALampCPP* Lamp = Cast<ALampCPP>(FoundActors[i]);
            Lamp->ToggleLight();

        }

        //simulate button release (Visual)
        cubeMeshComponent->SetRelativeScale3D(FVector(1, 1, 0.25f));

    }
}

