#pragma once
#include <DxLib.h>
#include "../../Util/Pad.h"
#include "../../Util/Pad2.h"
#include "../../Util/Vec2.h"
#include<array>

class ShotBase;
class ShotNull;

namespace
{
	constexpr int kShotMax = 4;	// ショット数最大
}

class PlayerBase //プレイヤーの基底クラス
{
public:
	PlayerBase();
	
	virtual ~PlayerBase() {};

	virtual void Init  () {};// 初期化
	virtual void End   () {};// 終了処理
	virtual void Update() {};// 更新
	virtual void Draw  () {};// 描画

	// プレイヤーのサイズの当たり判定
	int GetSizeLeft() { return m_sizeLeft; }
	int GetSizeTop() { return m_sizeTop; }
	int GetSizeRight() { return m_sizeRight; }
	int GetSizeBottom() { return m_sizeBottom; }
	
	// プレイヤーの攻撃の当たり判定
	int GetAttackSizeLeft() { return m_attackSizeLeft; }
	int GetAttackSizeTop() { return m_attackSizeTop; }
	int GetAttackSizeRight() { return m_attackSizeRight; }
	int GetAttackSizeBottom() { return m_attackSizeBottom; }

	bool GetAttackFlag() { return m_attackFlag; }


	int SetMove() { return m_moveType; }// SceneMainにどの攻撃をしているかを渡す
	void GetMove(int check) { m_moveType = check; }// SceneMainから攻撃状態を受け取る
	void GetDamage(int damage) { m_damage = damage; }// SceneMainからプレイヤーが受けるダメージを受け取る
	void OnDamage(int damage) { m_hp -= damage; }

	int GetHp() { return m_hp; }



	Vec2 GetPos() { return m_pos; }

protected:


	// プレイヤーのサイズ

	int m_sizeLeft = 0;
	int m_sizeTop = 0;
	int m_sizeRight = 0;
	int m_sizeBottom = 0;


	int m_sizeLeftAttack = 0;
	int m_sizeTopAttack = 0;
	int m_sizeRightAttack = 0;
	int m_sizeBottomAttack = 0;

	// 攻撃の判定
	int m_attackSizeLeft = 0;
	int m_attackSizeTop = 0;
	int m_attackSizeRight = 0;
	int m_attackSizeBottom = 0;


	int m_moveType = 0;
	int m_hp     = 100;// プレイヤーの体力量(100が標準)
	int m_damage = 10; // プレイヤーが受けるダメージ

	bool m_attackFlag = false;// 攻撃中かどうか

	Vec2 m_pos = { 0.0f,0.0f };// 位置
	Vec2 m_vec = { 0.0f,0.0f };// 運動量

	std::array<ShotBase*, kShotMax> m_Shot;
};

