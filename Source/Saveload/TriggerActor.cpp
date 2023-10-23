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
	FTimerHandle handle;
	FTimerHandle GravityTimerHandle;
	float GravityTime = 3;
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

// Called every frame
void ATriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	static float time = 0.f;
	time += DeltaTime;
	if (time <= 3) return;
	SaveLoad();
	SetActorTickEnabled(false);
}
