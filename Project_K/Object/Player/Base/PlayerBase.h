#pragma once
#include <DxLib.h>
#include "../../Util/Pad.h"
#include "../../Util/Vec2.h"

class PlayerBase //プレイヤーの基底クラス
{
public:
	PlayerBase() {};
	virtual ~PlayerBase() {};

	virtual void Init  () {};// 初期化
	virtual void End   () {};// 終了処理
	virtual void Update() {};// 更新
	virtual void Draw  () {};// 描画
	
	int SetPosLeft  () { return m_posLeft;   }// SceneMainにプレイヤーの位置を渡す
	int SetPosTop   () { return m_posTop;    }
	int SetPosRight () { return m_posRight;  }
	int SetPosBottom() { return m_posBottom; }

	int SetMove() { return m_moveType; }// SceneMainにどの攻撃をしているかを渡す
	void GetMove(int check) { m_moveType = check; }// SceneMainから攻撃状態を受け取る
	void GetDamage(int damage) { m_damage = damage; }// SceneMainからプレイヤーが受けるダメージを受け取る

	Vec2 SetPos() { return m_pos; }

protected:
	int m_posLeft   = 0;// プレイヤーの位置(当たり判用定)
	int m_posTop    = 0;
	int m_posRight  = 0;
	int m_posBottom = 0;

	int m_moveType = 0;
	int m_hp     = 100;// プレイヤーの体力量(100が標準)
	int m_damage = 0; // プレイヤーが受けるダメージ

	Vec2 m_pos = { 0.0f,0.0f };// 位置
	Vec2 m_vec = { 0.0f,0.0f };// 運動量
};

