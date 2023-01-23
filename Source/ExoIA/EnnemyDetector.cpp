// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemyDetector.h"

UEnnemyDetector::UEnnemyDetector()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UEnnemyDetector::BeginPlay()
{
	Super::BeginPlay();
	
}


void UEnnemyDetector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

