// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystemBase.generated.h"

// �g���pBP�̃x�[�X�ƂȂ�N���X
UCLASS(Abstract, Blueprintable, MinimalAPI, meta = (ShowWorldContextPin))
class UMyGameInstanceSubsystemHelperBase : public UObject
{
	GENERATED_BODY()

public:
	// �����̒��g��BP���ŏ������Ƃ�錾
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
