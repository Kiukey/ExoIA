// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DetectSightsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXOIA_API UDetectSightsComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
		float sightRange = 200;
	
public:	
	UDetectSightsComponent();

	FORCEINLINE bool IsInSight() 
	{
		if (!target)
			return false;
		return (target->GetActorLocation() - GetOwner()->GetActorLocation()).Size() < sightRange;
	}

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
