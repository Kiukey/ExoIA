// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "DetectSightsComponent.h"
#include "PatrolToChaseTransition.generated.h"

/**
 * 
 */
UCLASS()
class EXOIA_API UPatrolToChaseTransition : public UTransition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UDetectSightsComponent> sight = nullptr;

public:

	virtual bool IsValid() override;
	virtual void InitTransition(UFSM* _owner) override;
	virtual void CallNext() override;
};
