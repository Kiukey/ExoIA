// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnnemyDetector.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXOIA_API UEnnemyDetector : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
		float minDistance = 10;
	UPROPERTY(EditAnywhere)
		float moveSpeed = 1;
	UPROPERTY(EditAnywhere)
		bool moveState = false;
public:	
	UEnnemyDetector();
	float GetDistance() { return FVector::Dist(GetOwner()->GetActorLocation(), target->GetActorLocation()); }
	void MovingState(bool _state);
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:

	void ChaseTarget();
		
};
