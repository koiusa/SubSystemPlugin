# SubSystemPlugin
SubSystemPluginForUE

プロジェクト概要  
・UnrealEngineのSubSystemのひな形  
・MyGameInstanceSubsystemHelperの呼び出しのみGameModeに実装

## Config For MySubSystemPlugin
DefaultEngine.ini
```
[/Script/MySubsystem.MySubsystemConfig]
GameInstanceSubsystemBluePrint=/MySubystem/GameInstance/BP_MyGameInstanceSubsystemHelper
``````
※SubSystemの内容を定義するBPのパスを記述する