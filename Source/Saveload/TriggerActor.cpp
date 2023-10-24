// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerActor.h"
#include "Components/BoxComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATriggerActor::ATriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetRootComponent(Box);
}

// Called when the game starts or when spawned
void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
	UMyGameInstance* inst = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));
} 

void ATriggerActor::SaveLoad()
{
	UMyGameInstance* inst = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (UGameplayStatics::DoesSaveGameExist(inst->SlotName, inst->Index))
	{
		inst->LoadJson();
		UE_LOG(LogTemp, Log, TEXT("Save loaded"));
	}
	else
	{
		inst->SaveActorToJson();
		UE_LOG(LogTemp, Log, TEXT("Saved"));
	}
}

void ATriggerActor::CountDown()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("%d second to save/load"), counter--));
	}	
	if (counter < 0)
	{
		GetWorldTimerManager().ClearTimer(handle);
		SaveLoad();
	}
}

// Called every frame
void ATriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	static bool flag = true;
	if (flag) GetWorldTimerManager().SetTimer(handle, this, &ATriggerActor::CountDown, 1.0f, true);
	SetActorTickEnabled(false);
}
