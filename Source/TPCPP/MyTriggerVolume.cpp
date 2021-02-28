// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyTriggerVolume.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AMyTriggerVolume::AMyTriggerVolume()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapEnd);

    // Set the component's mesh
   /* cubeMeshComponent->SetStaticMesh(cubeMesh);
    cubeMeshComponent->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
    // Set as root component
    RootComponent = cubeMeshComponent;*/
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
    Super::BeginPlay();
    
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALampCPP::StaticClass(), FoundActors);

    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 999, 0, 5);
}

void AMyTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && OtherActor != this)
    {
       /* if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));
        };*/

        for (int i = 0; i < FoundActors.Num(); i++) 
        {
            ALampCPP* Lamp = Cast<ALampCPP>(FoundActors[i]);
            Lamp->ToggleLight();
            
        }
       
    }
}

void AMyTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this)
    {
       /* if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Volume"), *OtherActor->GetName()));
        }*/

        for (int i = 0; i < FoundActors.Num(); i++)
        {
            ALampCPP* Lamp = Cast<ALampCPP>(FoundActors[i]);
            Lamp->ToggleLight();

        }

    }
}