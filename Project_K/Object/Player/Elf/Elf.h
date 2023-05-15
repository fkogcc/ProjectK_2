#pragma once

#include "../Base/PlayerBase.h"

class ElfIdle;
class ElfRun;
class ElfAttackArrowChargeShot;
class ElfAttackArrowShot;
class ElfAttackArrowPunch;
class ElfAttackArrowUp;

class Elf : public PlayerBase
{
public:
	Elf();
	~Elf();

	void Init();// ‰Šú‰»
	void End();// I—¹ˆ—
	void Update();// XV
	void Draw();// •`‰æ

	void AnimationSwitch();

private:
	int m_handle;// ‰æ‘œƒnƒ“ƒhƒ‹

	int m_imageX, m_imageY;// ‰æ‘œ•`‰æˆÊ’u

//	int m_temp

	bool m_isAttack;// 

	bool m_isDirection;// 

	bool m_isCollPos;

	ElfIdle* m_pIdle;// ‘Ò‹@
	ElfRun* m_pRun; // ‘–‚è
	ElfAttackArrowChargeShot* m_pChargeShot;// UŒ‚
	ElfAttackArrowShot* m_pShot;      // UŒ‚
	ElfAttackArrowPunch* m_pPunch;     // UŒ‚
	ElfAttackArrowUp* m_pUp;        // UŒ‚
};


