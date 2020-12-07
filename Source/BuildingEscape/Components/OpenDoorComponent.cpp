#include "OpenDoorComponent.h"

#include <GameFramework/Actor.h>

// Sets default values for this component's properties
UOpenDoorComponent::UOpenDoorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoorComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoorComponent::TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	FRotator rotation = GetOwner()->GetActorRotation();

	// open rotation
	rotation.Yaw = FMath::FInterpConstantTo(rotation.Yaw, TargetYam, deltaTime, 45);

	GetOwner()->SetActorRotation(rotation);
}

