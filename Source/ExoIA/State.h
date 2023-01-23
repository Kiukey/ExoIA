// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSM.h"
#include "Transition.h"
#include "State.generated.h"


class UFSM;

UCLASS()
class EXOIA_API UState : public UObject
{
	GENERATED_BODY()
	
protected:
	UPROPERTY() TObjectPtr<UTransition> transition = nullptr;
	UPROPERTY() TObjectPtr<UFSM> owner = nullptr;
	UPROPERTY()
		TArray<UTransition*> transitions;

public:

	virtual void OnEnter(UFSM* _owner);
	virtual void OnUpdate();
	virtual void OnExit();
	virtual void DebugState();
};
