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

	void Init();// ������
	void End();// �I������
	void Update();// �X�V
	void Draw();// �`��

	void AnimationSwitch();

private:
	int m_handle;// �摜�n���h��

	int m_imageX, m_imageY;// �摜�`��ʒu

//	int m_temp

	bool m_isAttack;// 

	bool m_isDirection;// 

	bool m_isCollPos;

	ElfIdle* m_pIdle;// �ҋ@
	ElfRun* m_pRun; // ����
	ElfAttackArrowChargeShot* m_pChargeShot;// �U��
	ElfAttackArrowShot* m_pShot;      // �U��
	ElfAttackArrowPunch* m_pPunch;     // �U��
	ElfAttackArrowUp* m_pUp;        // �U��
};


