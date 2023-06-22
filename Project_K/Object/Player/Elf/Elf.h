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
private:

	void UpdateControl();// ����

	void AnimStop();// �A�j���[�V������~

	void AnimSwitch();// �A�j���ƍU���͈͂��w��

	void UpdateHitColl();// ���g�̓����蔻��

	void UpdateGravity();// �d�͊֘A

	void AnimIdol(); // �ҋ@��ԃA�j���[�V����
	void AnimRun();  // ����A�j���[�V����
	void AnimJump(); // �W�����v�A�j���[�V����
	void AnimAttackPunch();     // �p���`�A�j���[�V����
	void AnimAttackNormalShot();// �ʏ�V���b�g�A�j���[�V����
	void AnimAttackChargeShit();// �`���[�W�V���b�g�A�j���[�V����
	void AnimAttackUpShit();    // ��U���A�j���[�V����

private:
	int m_handle;// �摜�n���h��

	int m_imageX, m_imageY;// �摜�`��ʒu

	int m_gapTime;

	int m_chargeHitPos = 0;

	int m_chargeShotCount = 0;

	float m_jumpAcc = 0.0f;

	bool m_isAttack;// �U�����ł��邩�ǂ���

	bool m_isAttackHit;

	bool m_isDirection;// �����Ă������

	ElfIdle* m_pIdle;// �ҋ@
	ElfRun* m_pRun; // ����
	ElfJump* m_pJump;
	ElfAttackArrowChargeShot* m_pChargeShot;// �U��
	ElfAttackArrowShot* m_pShoot;      // �U��
	ElfAttackArrowPunch* m_pPunch;     // �U��
	ElfAttackArrowUp* m_pUp;        // �U��


};


