// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystemBase.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

UMyGameInstanceSubsystem::UMyGameInstanceSubsystem()
{
    // �g���pBP�̃N���X���������E�擾�B�p�X�̎w��ɂ͒���
    // .ini �� �v���W�F�N�g�ݒ��BP�A�Z�b�g�̃p�X��ݒ�ł���悤�ɂ��Ă����Ɛe��
    FString MySubsystemConfig;
    if (GConfig->GetString(TEXT("/Script/MySubsystem.MySubsystemConfig"), TEXT("GameInstanceSubsystemBluePrint"), MySubsystemConfig, GEngineIni))
    {
        static ConstructorHelpers::FClassFinder<UMyGameInstanceSubsystemHelperBase> BluePrintFile(*MySubsystemConfig);
        if (BluePrintFile.Class)
        {
            SubsystemHelperClass = (UClass*)BluePrintFile.Class;
        }
    }
}

void UMyGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    SubsystemHelper = nullptr;

    if (SubsystemHelperClass)
    {
        // �g���pBP�𐶐��E�ݒ�
        SubsystemHelper = NewObject<UMyGameInstanceSubsystemHelperBase>(GetTransientPackage(), SubsystemHelperClass);
    }
}

void UMyGameInstanceSubsystem::Deinitialize()
{
    SubsystemHelper = nullptr;
}
