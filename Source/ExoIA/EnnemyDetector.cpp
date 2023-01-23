// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemyDetector.h"

UEnnemyDetector::UEnnemyDetector()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEnnemyDetector::MovingState(bool _state)
{
	moveState = _state;
}


void UEnnemyDetector::BeginPlay()
{
	Super::BeginPlay();
}

void UEnnemyDetector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ChaseTarget();
}

void UEnnemyDetector::ChaseTarget()
{
	if (!moveState)
		return;

	FVector _newPosition = FMath::VInterpConstantTo(GetOwner()->GetActorLocation(), target->GetActorLocation(), GetWorld()->DeltaTimeSeconds, moveSpeed);
	GetOwner()->SetActorLocation(_newPosition);
}