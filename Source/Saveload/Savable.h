#pragma once
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SharedPointer.h"
#include "Savable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, MinimalAPI)
class USavable : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class SAVELOAD_API ISavable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
	void SetActorToSavableList();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
	FString JsonSerialize();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
	void JsonDeserialize();
};
