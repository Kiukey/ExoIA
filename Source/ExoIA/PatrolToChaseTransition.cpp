// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolToChaseTransition.h"
#include "FSM.h"
#include "ChaseState.h"

bool UPatrolToChaseTransition::IsValid()
{
	if (!detector)
		return true;

	return detector->GetDistance() < 200;
}

void UPatrolToChaseTransition::InitTransition(UFSM* _owner)
{
	Super::InitTransition(_owner);

	detector = Cast<UEnnemyDetector>(_owner->GetOwner()->GetComponentByClass(UEnnemyDetector::StaticClass()));

}

void UPatrolToChaseTransition::CallNext()
{
	Super::CallNext();
	//UE_LOG(LogTemp, Warning, TEXT("NEW STATE HERE (CALL NEXT UPATROLTOCHASE"));
	owner->SetNext<UChaseState>();

}
