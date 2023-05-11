#pragma once
#include <DxLib.h>
#include "../../Util/Pad.h"
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

	// プレイヤーのサイズ取得
	int GetAttackSizeLeft() { return m_sizeLeft; }
	int GetAttackSizeTop() { return m_sizeTop; }
	int GetAttackSizeRight() { return m_sizeRight; }
	int GetAttackSizeBottom() { return m_sizeBottom; }
	
	// プレイヤーの攻撃判定取得取得
	int GetSizeAttackLeft() { return m_sizeLeftAttack; }
	int GetSizeAttackTop() { return m_sizeTopAttack; }
	int GetSizeAttackRight() { return m_sizeRightAttack; }
	int GetSizeAttackBottom() { return m_sizeBottomAttack; }

	int SetMove() { return m_moveType; }// SceneMainにどの攻撃をしているかを渡す
	void GetMove(int check) { m_moveType = check; }// SceneMainから攻撃状態を受け取る
	void GetDamage(int damage) { m_damage = damage; }// SceneMainからプレイヤーが受けるダメージを受け取る

	Vec2 SetPos() { return m_pos; }

protected:
	int m_sizeLeft = 0;
	int m_sizeTop = 0;
	int m_sizeRight = 0;
	int m_sizeBottom = 0;

	int m_sizeLeftAttack = 0;
	int m_sizeTopAttack = 0;
	int m_sizeRightAttack = 0;
	int m_sizeBottomAttack = 0;

	int m_moveType = 0;
	int m_hp     = 100;// プレイヤーの体力量(100が標準)
	int m_damage = 10; // プレイヤーが受けるダメージ

	bool m_attackFlag = false;// 攻撃中かどうか

	Vec2 m_pos = { 0.0f,0.0f };// 位置
	Vec2 m_vec = { 0.0f,0.0f };// 運動量

	std::array<ShotBase*, kShotMax> m_Shot;
};

