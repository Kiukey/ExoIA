// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleToPatrolTransition.h"
#include "PatrolState.h"

bool UIdleToPatrolTransition::IsValid()
{
	waitTime += GetWorld()->DeltaTimeSeconds;
	return waitTime > timeToWait;
}

void UIdleToPatrolTransition::CallNext()
{
	Super::CallNext();

	owner->SetNext<UPatrolState>();

}

void UIdleToPatrolTransition::InitTransition(UFSM* _owner)
{
	Super::InitTransition(_owner);
	timeToWait = FMath::RandRange(minTimer, maxTimer);
}
