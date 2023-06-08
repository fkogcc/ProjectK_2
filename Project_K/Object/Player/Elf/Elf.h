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

	void Init();// ������
	void End();// �I������
	void Update();// �X�V
	void Draw();// �`��

	void AnimStop();// �A�j���[�V������~

	void AnimSwitch();// �A�j��

//	void AnimDamageStop(bool damageFlg) { m_isAttackStop = damageFlg; }

private:
	int m_handle;// �摜�n���h��

	int m_imageX, m_imageY;// �摜�`��ʒu

	float m_jumpAcc = 0.0f;

	bool m_isAttack;// �U�����ł��邩�ǂ���

	bool m_isDirection;// 

	bool m_isCollPos;

	ElfIdle* m_pIdle;// �ҋ@
	ElfRun* m_pRun; // ����
	ElfJump* m_pJump;
	ElfAttackArrowChargeShot* m_pChargeShot;// �U��
	ElfAttackArrowShot* m_pShot;      // �U��
	ElfAttackArrowPunch* m_pPunch;     // �U��
	ElfAttackArrowUp* m_pUp;        // �U��
};


