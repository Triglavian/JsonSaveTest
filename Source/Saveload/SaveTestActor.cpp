// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveTestActor.h"
#include "MyGameInstance.h"
#include "SaveData.h"
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
	FUSaveData save = FUSaveData(this);

	FString str = save.JsonSerialize();
	return str;
}

void ASaveTestActor::JsonDeserialize_Implementation()
{
	UMyGameInstance* inst = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));
	UE_LOG(LogTemp, Log, TEXT("Try to find data : %s"), *GetActorLabel());
	auto jsonData = inst->FindJsonByLabel(GetActorLabel());
	if (nullptr == jsonData)
	{
		UE_LOG(LogTemp, Log, TEXT("Failed to find data by actor name"));
		return;
	}
	FUSaveData data = FUSaveData(this);
	data.SetDeserializedData(jsonData, this);
	UE_LOG(LogTemp, Log, TEXT("ActorLabel : %s, var: %d, Str: %s, Flag = %d"), *GetActorLabel(), var, *Str, flag == true ? 1 : 0);
}

