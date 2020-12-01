#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>

#include "WorldPositionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UWorldPositionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWorldPositionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
