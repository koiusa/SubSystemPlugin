// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystemBase.generated.h"

// 拡張用BPのベースとなるクラス
UCLASS(Abstract, Blueprintable, MinimalAPI, meta = (ShowWorldContextPin))
class UMyGameInstanceSubsystemHelperBase : public UObject
{
	GENERATED_BODY()

public:
	// 処理の中身はBP側で書くことを宣言
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TestFunc();
};

/**
 * 
 */
UCLASS()
class UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UMyGameInstanceSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(Transient, BlueprintReadOnly)
	UMyGameInstanceSubsystemHelperBase* SubsystemHelper;

private:
	TSubclassOf< class UMyGameInstanceSubsystemHelperBase > SubsystemHelperClass;
};
