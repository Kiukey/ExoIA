// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transition.h"
#include "IdleToPatrolTransition.generated.h"

UCLASS()
class EXOIA_API UIdleToPatrolTransition : public UTransition
{
	GENERATED_BODY()

	float waitTime = 0;
	float timeToWait = 5;
	float maxTimer = 5, minTimer = 1;
protected:

	virtual bool IsValid() override;
	virtual void CallNext() override;
	virtual void InitTransition(UFSM* _owner) override;
};
