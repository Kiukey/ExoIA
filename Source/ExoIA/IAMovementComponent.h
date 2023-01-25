// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Waypoint.h"
#include "IAMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXOIA_API UIAMovementComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<AActor> owner = nullptr;
	UPROPERTY(EditAnywhere)
		TArray<AWaypoint*> positions;
	UPROPERTY(VisibleAnywhere)
		int currentPosition = 0;
	UPROPERTY(EditAnywhere)
		bool moveToPositions = false;
	UPROPERTY(EditAnywhere)
		float movementSpeed = 1;
public:	
	UIAMovementComponent();
	FORCEINLINE int GetCurrentPosition() { return currentPosition; }
	void StartMoving();
	FORCEINLINE bool IsAtDestination() { return currentPosition >= positions.Num(); }
	void StopMoving();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	void MoveToTarget();
	void DebugPositions();
};
