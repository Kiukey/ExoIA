// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectSightsComponent.h"

UDetectSightsComponent::UDetectSightsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UDetectSightsComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UDetectSightsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!target)
		return;
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), target->GetActorLocation(), FColor::Magenta);
}

