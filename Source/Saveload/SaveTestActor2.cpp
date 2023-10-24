// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveTestActor2.h"

// Sets default values
ASaveTestActor2::ASaveTestActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASaveTestActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASaveTestActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASaveTestActor2::SetActorToSavableList_Implementation()
{
}

FString ASaveTestActor2::JsonSerialize_Implementation()
{
	return FString();
}

void ASaveTestActor2::JsonDeserialize_Implementation()
{
}

