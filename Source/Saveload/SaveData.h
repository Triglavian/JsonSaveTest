// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveData.generated.h"

/**
 * 
 */
UCLASS()
class SAVELOAD_API USaveData : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FVector Location;
	UPROPERTY()
	int var;
	UPROPERTY()
	bool Flag;
	UPROPERTY()
	FString Str;
	void Init(class ASaveTestActor* Actor);
	FString JsonSerialize();
};
