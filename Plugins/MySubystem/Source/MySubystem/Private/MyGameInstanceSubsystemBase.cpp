// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystemBase.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

UMyGameInstanceSubsystem::UMyGameInstanceSubsystem()
{
    // 拡張用BPのクラス情報を検索・取得。パスの指定には注意
    // .ini や プロジェクト設定でBPアセットのパスを設定できるようにしておくと親切
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
        // 拡張用BPを生成・設定
        SubsystemHelper = NewObject<UMyGameInstanceSubsystemHelperBase>(GetTransientPackage(), SubsystemHelperClass);
    }
}

void UMyGameInstanceSubsystem::Deinitialize()
{
    SubsystemHelper = nullptr;
}
