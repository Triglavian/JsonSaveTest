// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Savable.h"
#include "TestComponent.generated.h"

UCLASS()
class SAVELOAD_API ATestComponent : public AActor, public ISavable
{
	GENERATED_BODY()
	class TestComponent2* Comp2;
public:	
	// Sets default values for this actor's properties
	ATestComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save");
	int var;
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
