// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "ChaseState.generated.h"

/**
 * 
 */
UCLASS()
class EXOIA_API UChaseState : public UState
{
	GENERATED_BODY()
	

	virtual void OnEnter(UFSM* _owner) override;
	virtual void OnUpdate() override;
	virtual void OnExit() override;
	virtual void DebugState() override;
};
