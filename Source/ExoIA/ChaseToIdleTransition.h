// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "DetectSightsComponent.h"
#include "ChaseToIdleTransition.generated.h"

/**
 * 
 */
UCLASS()
class EXOIA_API UChaseToIdleTransition : public UTransition
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
		TObjectPtr<UDetectSightsComponent> sight = nullptr;

protected:

	virtual bool IsValid() override;
	virtual void CallNext() override;
	virtual void InitTransition(UFSM* _owner) override;
};
