// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "IdleState.generated.h"

/**
 * 
 */
UCLASS()
class EXOIA_API UIdleState : public UState
{
	GENERATED_BODY()
	

protected:

	virtual void OnEnter(UFSM* _owner) override;
	virtual void OnUpdate() override;
	virtual void OnExit() override;
	virtual void DebugState() override;
};
