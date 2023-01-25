// Fill out your copyright notice in the Description page of Project Settings.


#include "IAMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


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
	
	const FVector _newPosition = FMath::VInterpConstantTo(owner->GetActorLocation(), positions[currentPosition]->GetActorLocation(), TIME, movementSpeed);
	owner->SetActorLocation(_newPosition);

	if (FVector::Dist(owner->GetActorLocation(), positions[currentPosition]->GetActorLocation()) < 10)
	{
		currentPosition++;
		
		if (IsAtDestination())
		{
			StopMoving();
			return;
		}
	}
	const FRotator _find = UKismetMathLibrary::FindLookAtRotation(positions[currentPosition]->GetActorLocation(), owner->GetActorLocation());
	FRotator _currentRotation = FMath::RInterpConstantTo(owner->GetActorRotation(), _find, TIME, movementSpeed);
	_currentRotation.Pitch = 0;
	_currentRotation.Roll = 0;
	owner->SetActorRotation(_currentRotation);
}

void UIAMovementComponent::DebugPositions()
{
	for (int i = 0; i < positions.Num() - 1; i++)
	{
		DrawDebugLine(WORLD, positions[i]->GetActorLocation(), positions[i + 1]->GetActorLocation(), FColor::Green);
	}
}

