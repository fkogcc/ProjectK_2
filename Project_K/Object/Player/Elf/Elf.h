#pragma once

#include "../Base/PlayerBase.h"

#include <vector>

class ElfIdle;
class ElfRun;
class ElfJump;
class ElfAttackArrowChargeShot;
class ElfAttackArrowShot;
class ElfAttackArrowPunch;
class ElfAttackArrowUp;

//class ShotBase;

class Elf : public PlayerBase
{
public:
	Elf();
	~Elf();

	void Init();// 初期化
	void End();// 終了処理
	void Update();// 更新
	void Draw();// 描画

	void AnimStop();// アニメーション停止

	void AnimSwitch();// アニメ

//	void AnimDamageStop(bool damageFlg) { m_isAttackStop = damageFlg; }

private:
	int m_handle;// 画像ハンドル

	int m_imageX, m_imageY;// 画像描画位置

	float m_jumpAcc = 0.0f;

	bool m_isAttack;// 攻撃ができるかどうか

	bool m_isDirection;// 

	bool m_isCollPos;

	ElfIdle* m_pIdle;// 待機
	ElfRun* m_pRun; // 走り
	ElfJump* m_pJump;
	ElfAttackArrowChargeShot* m_pChargeShot;// 攻撃
	ElfAttackArrowShot* m_pShot;      // 攻撃
	ElfAttackArrowPunch* m_pPunch;     // 攻撃
	ElfAttackArrowUp* m_pUp;        // 攻撃
};


