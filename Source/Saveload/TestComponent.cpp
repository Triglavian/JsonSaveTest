// Fill out your copyright notice in the Description page of Project Settings.


#include "TestComponent.h"

// Sets default values
ATestComponent::ATestComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestComponent::SetActorToSavableList_Implementation()
{
}

FString ATestComponent::JsonSerialize_Implementation()
{
	return FString();
}

void ATestComponent::JsonDeserialize_Implementation()
{
}

