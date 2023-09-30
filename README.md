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



---
## Reference

実装参考サイト  
https://qiita.com/EGJ-Kaz_Okada/items/0ae2e8d8ba901c6a978d?fbclid=IwAR2_ygPhJFNGqJ79kFbFmey_k-K3uf00m7fSZc2K_KGOLJeUzN2WixYmd3o

SubSystemの処理内容、実装の参考はこの辺とかどうだろう
https://qiita.com/unknown_ds/items/afcff802ab17db486822