// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSaveData.generated.h"

/**
 * 
 */
USTRUCT()
struct SAVELOAD_API FUSSaveData
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
	void JsonDeserialize(const TSharedPtr<FJsonObject>& JsonObject);
	void SetDeserializedData(ASaveTestActor* Actor);
private:
	void JsonDeserializeLocation(const TSharedPtr<FJsonObject>& JsonObject);
};
