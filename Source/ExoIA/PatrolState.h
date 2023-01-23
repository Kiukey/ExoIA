// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "IAMovementComponent.h"
#include "PatrolState.generated.h"


UCLASS()
class EXOIA_API UPatrolState : public UState
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		TObjectPtr<UIAMovementComponent> movementComponent = nullptr;

protected:

	virtual void OnEnter(UFSM* _owner) override;
	virtual void OnUpdate() override;
	virtual void OnExit() override;
	virtual void DebugState() override;

};
