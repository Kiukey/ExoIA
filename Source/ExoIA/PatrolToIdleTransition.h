// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "IAMovementComponent.h"
#include "PatrolToIdleTransition.generated.h"

/**
 * 
 */
UCLASS()
class EXOIA_API UPatrolToIdleTransition : public UTransition
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UIAMovementComponent> iaMovementComponent = nullptr;
protected:
	virtual bool IsValid() override;
	virtual void CallNext() override;
	virtual void InitTransition(UFSM* _owner);
};
