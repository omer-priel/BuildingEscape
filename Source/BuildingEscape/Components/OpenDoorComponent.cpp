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

	InitialYam = GetOwner()->GetActorRotation().Yaw;
	TargetYam = InitialYam + 90.0f;
}


// Called every frame
void UOpenDoorComponent::TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	FRotator rotation = GetOwner()->GetActorRotation();

	// open rotation
	rotation.Yaw = FMath::FInterpTo(rotation.Yaw, TargetYam, deltaTime, 2);

	GetOwner()->SetActorRotation(rotation);
}