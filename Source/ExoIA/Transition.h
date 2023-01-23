// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.generated.h"

class UFSM;
class UState;

UCLASS()
class EXOIA_API UTransition : public UObject
{
	GENERATED_BODY()
protected: 
	UPROPERTY() TObjectPtr<UFSM> owner = nullptr;

public:
	virtual bool IsValid();
	virtual void CallNext();
	virtual void InitTransition(UFSM* _owner);
};
