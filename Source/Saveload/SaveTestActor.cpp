// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveTestActor.h"
#include "MyGameInstance.h"
#include "SSaveData.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASaveTestActor::ASaveTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASaveTestActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorToSavableList_Implementation();
}

// Called every frame
void ASaveTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASaveTestActor::SetActorToSavableList_Implementation()
{
	UMyGameInstance* inst = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));
	inst->SetActorToList(this);
}

FString ASaveTestActor::JsonSerialize_Implementation()
{
	FUSSaveData save = FUSSaveData();
	save.Init(this);
	//if (nullptr == save)
	//{
	//	UE_LOG(LogTemp, Log, TEXT("Failed to create save data"));
	//	return TEXT("");
	//}
	//save->Init(this);
	FString str = save.JsonSerialize();
	UE_LOG(LogTemp, Log, TEXT("Serialized str = %s\n\n"), *str);
	return str;
}

void ASaveTestActor::JsonDeserialize_Implementation(const TSharedPtr<FJsonObject>& JsonObject)
{
	FUSSaveData save = FUSSaveData();
	save.JsonDeserialize(JsonObject);
	save.SetDeserializedData(this);
}

