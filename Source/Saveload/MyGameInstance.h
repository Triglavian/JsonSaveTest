// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SaveSystem.h"
#include "Savable.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	TArray<AActor*> Actors;
	FString SlotName = TEXT("Save");
	int Index = 1;
	friend class ATriggerActor;
public:
	void SetActorToList(AActor* Actor);
	void SaveActorToJson();
	void LoadJson();
};
