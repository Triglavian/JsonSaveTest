// Fill out your copyright notice in the Description page of Project Settings.


#include "TestComponent2.h"

// Sets default values
ATestComponent2::ATestComponent2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestComponent2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestComponent2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestComponent2::SetActorToSavableList_Implementation()
{
}

FString ATestComponent2::JsonSerialize_Implementation()
{
	return FString();
}

void ATestComponent2::JsonDeserialize_Implementation()
{
}

