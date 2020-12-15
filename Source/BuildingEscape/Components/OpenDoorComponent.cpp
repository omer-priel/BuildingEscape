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
	TargetYam += InitialYam;
}


// Called every frame
void UOpenDoorComponent::TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	FRotator rotation = GetOwner()->GetActorRotation();

	// open rotation
	rotation.Yaw = FMath::Lerp(rotation.Yaw, TargetYam, deltaTime * 0.6f);

	GetOwner()->SetActorRotation(rotation);
}