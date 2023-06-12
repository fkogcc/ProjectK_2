#pragma once

#include "../Base/PlayerBase.h"
// �K�v�ȃN���X�̐錾
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
	Witch();// �R���X�g���N�^
	virtual ~Witch();// �f�X�g���N�^

	// ������
	void Init();
	// �X�V����
	void Update();
	// �`�揈��
	void Draw();

	// �p�b�h�������ꂽ���̏��
	void UpdateInputKey();
	// �v���C���[�̏��
	void UpdatePlayerState();
	// �v���C���[�̃W�����v����
	void UpdateJump();
	// �v���C���[�̒ʏ��ԃA�j���[�V��������
	void UpdateAnim();
	// �v���C���[�̎��S�A�j���[�V��������
	void UpdateDead();
	//�v���C���[�̓����蔻��
	void UpdatePlayerJudge();
	//�v���C���[�̍U���̓����蔻��
	void UpdateAttackJudge();
private:
	// �����̏�Ԃ̃N���X�̃��[�h
	WitchIdle* m_pIdle;// �A�C�h�����
	WitchRun* m_pRun;// �����Ă�
	WitchShotAttack* m_pShot;// �������Ⴂ�X
	WitchLongShotAttack* m_pLongShot;// �l�A�X
	WitchCharge* m_pCharge;// �`���[�W
	Chicken* m_pChicken;// �ɂ�Ƃ�
	KnightCat* m_pKnightCat;// �˂������
	WitchDead* m_pDead;// ���S

	int m_handle;// �摜
	int m_animeWidth;// �摜�̉�
	int m_animeHight;// �摜�̏c
	bool m_reversal;// �摜�𔽓]�����邩�ǂ���
	int m_animeLoopCount;// �`���[�W����Ƃ��̃��[�v����񐔂������ϐ�
	int m_LoopCount;// ���񃋁[�v������������ϐ�
	int m_animeFrame;//�A�j���[�V�����̑���
	int m_animeMax;//�A�j���[�V�����̍ő�l
	int m_indexX;// �摜�̉��̐؂��蕝
	float m_playerjudge;// �摜�ɂ�邸���␳����ϐ�
	int m_shiftX;// �摜�̃T�C�Y���Ⴄ���Ƃɂ�����␳����ϐ�
	bool m_animeFlag;// �A�j���[�V�������s���Ă��邩�̃t���O

	float m_temp;// �W�����v�p�Ɍ����������������ϐ�
	bool m_jumpFlag;// �W�����v�����ǂ����̃t���O
	int m_jumpPower;// �W�����v�̃p���[
	bool m_tempFlag1;// �U�������i�ɂ�Ƃ�j�@�͋Ǝ����̂��߂ɗp�ӂ��܂�������1
	bool m_tempFlag2;// �U�������i�˂������j�͋Ǝ����̂��߂ɗp�ӂ��܂�������2
	int m_movement;// �W�����v����Ƃ���X�𓮂�����
};