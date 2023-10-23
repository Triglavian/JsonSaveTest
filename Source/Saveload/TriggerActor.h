// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerActor.generated.h"

UCLASS()
class SAVELOAD_API ATriggerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	class UBoxComponent* Box;
	void SaveLoad();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
