#pragma once
#include <DxLib.h>

// ゲームシーン基底クラス
class SceneBase
{
public:
	SceneBase() {}
	virtual ~SceneBase() {}
	virtual void Init        () {			   }// 初期化
	virtual void End         ()	{			   }// 終了
	virtual SceneBase* Update() { return this; }// 毎フレームの処理
	virtual void Draw        ()	{              }// 描画
};

