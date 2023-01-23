// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSM.generated.h"


class UState;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXOIA_API UFSM : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere)
		TObjectPtr<UState> currentState = nullptr;
public:	
	UFSM();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void OnEnter();
	virtual void OnUpdate();
	virtual void OnExit();
public:	
	template<class T>
	void SetNext()
	{
		if (currentState)
		{
			currentState->OnExit();
			currentState = nullptr;
		}
		currentState = Cast<UState>(NewObject<T>(this));
		if (!currentState)
			return;
		currentState->OnEnter(this);
	}
};
