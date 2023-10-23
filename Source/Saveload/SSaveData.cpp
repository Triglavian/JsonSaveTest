// Fill out your copyright notice in the Description page of Project Settings.

#include "SSaveData.h"
#include "SaveTestActor.h"
#include "JsonUtilities.h"

void FUSSaveData::Init(ASaveTestActor* Actor)
{
	this->Location = Actor->GetActorLocation();
	this->var = Actor->var;
	this->Flag = Actor->flag;
	this->Str = Actor->Str;
	
}

FString FUSSaveData::JsonSerialize()
{
	FString str = TEXT("");
	FJsonObjectConverter::UStructToJsonObjectString(FUSSaveData::StaticStruct(), this, str, 0, 0);
	UE_LOG(LogTemp, Log, TEXT("Serialized : %s"), *str);
	return str;
}

void FUSSaveData::JsonDeserialize(const TSharedPtr<FJsonObject>& JsonObject)
{
	TArray<FString> Keys = TArray<FString>();

	for (auto& Field : JsonObject->Values)
	{
		FString FieldName = Field.Key;
		if ("Location" == FieldName)
		{
			JsonDeserializeLocation(Field.Value->AsObject());
			continue;
		}
		Keys.Add(Field.Key);
	}
	JsonObject->TryGetNumberField(Keys[0], var);
	JsonObject->TryGetBoolField(Keys[1], Flag);
	JsonObject->TryGetStringField(Keys[2], Str);

}

void FUSSaveData::SetDeserializedData(ASaveTestActor* Actor)
{
	Actor->SetActorLocation(this->Location);
	Actor->var = this->var;
	Actor->flag = this->Flag;
	Actor->Str = this->Str;
}

void FUSSaveData::JsonDeserializeLocation(const TSharedPtr<FJsonObject>& JsonObject)
{
	TArray<FString> Keys = TArray<FString>();
	for (auto& Field : JsonObject->Values)
	{
		Keys.Add(Field.Key);
	}
	JsonObject->TryGetNumberField(Keys[0], Location.X);
	JsonObject->TryGetNumberField(Keys[1], Location.Y);
	JsonObject->TryGetNumberField(Keys[2], Location.Z);
}
