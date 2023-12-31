// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Savable.h"
#include "Templates/SharedPointer.h"
#include "SaveTestActor.generated.h"

UCLASS()
class SAVELOAD_API ASaveTestActor : public AActor, public ISavable
{
	GENERATED_BODY()
	friend struct FUSaveData;
public:	
	// Sets default values for this actor's properties
	ASaveTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save");
	int var;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save");
	bool flag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save");
	FString Str;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
	void SetActorToSavableList();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
	FString JsonSerialize();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
	void JsonDeserialize();
	void SetActorToSavableList_Implementation();
	FString JsonSerialize_Implementation();
	void JsonDeserialize_Implementation();
};
