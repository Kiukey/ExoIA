// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM.h"
#include "GuardFSM.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EXOIA_API UGuardFSM : public UFSM
{
	GENERATED_BODY()
	
protected:

	virtual void OnEnter() override;
};
