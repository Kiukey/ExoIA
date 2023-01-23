// Fill out your copyright notice in the Description page of Project Settings.


#include "IAMovementComponent.h"

#define WORLD GetWorld()
#define TIME WORLD->DeltaTimeSeconds

UIAMovementComponent::UIAMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UIAMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	owner = GetOwner();
}

void UIAMovementComponent::StartMoving()
{
	moveToPositions = true;
	currentPosition = 0;
}

void UIAMovementComponent::StopMoving()
{
	moveToPositions = false;
}

void UIAMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToTarget();
	DebugPositions();
}

void UIAMovementComponent::MoveToTarget()
{
	if (!moveToPositions || positions.IsEmpty())
		return;
	
	FVector _newPosition = FMath::VInterpConstantTo(owner->GetActorLocation(), positions[currentPosition]->GetActorLocation(), TIME, movementSpeed);
	owner->SetActorLocation(_newPosition);

	if (FVector::Dist(owner->GetActorLocation(), positions[currentPosition]->GetActorLocation()) < 10)
	{
		currentPosition++;
		
		if (IsAtDestination())
			StopMoving();
	}
}

void UIAMovementComponent::DebugPositions()
{
	for (int i = 0; i < positions.Num() - 1; i++)
	{
		DrawDebugLine(WORLD, positions[i]->GetActorLocation(), positions[i + 1]->GetActorLocation(), FColor::Green);
	}
}

