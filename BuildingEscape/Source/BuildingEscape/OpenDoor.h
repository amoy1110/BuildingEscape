// Copyright Adam Moy 2017

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;

	float LastDoorOpenTime;

	//UPROPERTY(EditAnywhere)
	//AActor* ActorThatOpens; // pawn inherits from actor. no longer needed because we want 

	AActor* Owner = nullptr;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;
};
