// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveData.h"

void USaveData::Init(ASaveTestActor* Actor)
{
}

FString USaveData::JsonSerialize()
{
	FString str = TEXT("");
	//FJsonObjectConverter::UStructToJsonObjectString(USaveData::StaticClass(), this, str, 0, 0);
	return str;
}
