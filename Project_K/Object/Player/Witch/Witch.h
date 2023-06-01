#pragma once

#include "../Base/PlayerBase.h"
// 必要なクラスの宣言
class WitchIdle;
class WitchRun;
class WitchShotAttack;
class WitchLongShotAttack;
class WitchCharge;
class Chicken;
class KnightCat;
class WitchDead;

class Witch : public PlayerBase
{
public:
	Witch();
	virtual ~Witch();

	void Init();
	void Update();
	void Draw();

	void UpdateInputKey();
	void UpdatePlayerState();
	void UpdatePlayerJudge();
	void UpdateAttackJudge();
	void UpdateAnim();
	void UpdateDead();
	void UpdateJump();
private:
	WitchIdle* m_pIdle;
	WitchRun* m_pRun;
	WitchShotAttack* m_pShot;
	WitchLongShotAttack* m_pLongShot;
	WitchCharge* m_pCharge;
	Chicken* m_pChicken;
	KnightCat* m_pKnightCat;
	WitchDead* m_pDead;

	int m_handle;
	int m_animeHight;
	int m_animeWidth;
	bool m_reversal;
	int m_imageX;
	int m_imageY;
	int m_animeLoopCount;
	int m_LoopCount;
	int m_animeFrame;
	int m_animeMax;
	int m_indexX;
	float m_playerjudge;
	int m_shiftX;
	bool m_animeFlag;

	float m_emptyAttackLeft;
	float m_emptyAttackTop;
	float m_emptyAttackRight;
	float m_emptyAttackBottom;

	float m_empty;
	Vec2 m_vec;
	bool m_jumpFlag;
	int m_jumpPower;
	bool m_emptyCheckFlag;
	int m_movement;
};