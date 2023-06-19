#pragma once

#include "../Base/PlayerBase.h"

class KinnikuIdle;
class KinnikurouJab;
class KinnikuMuscle;
class KinnikuUpper;
class KinnikuMizo;
class KinnikuRun;
class KinnikuJump;
class KinnikuDead;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// ������
	void End   ();// �I������
	void Update();// �X�V
	void Draw()override;// �`��

	void ImgposInit();// �摜�ʒu�̏�����

	void AttackCol();// �U���̃^�C�~���O

	void InitAttackFlag();// �U���t���O�̏�����

private:
	// �|�C���^
	KinnikuIdle* m_pIdle;// �A�C�h�����
	KinnikurouJab* m_pJab;// �W���u�U�����
	KinnikuMuscle* m_pMuscle;// ���؏Ռ��g�U�����
	KinnikuUpper* m_pUpper;// �A�b�p�[�U�����
	KinnikuMizo* m_pMizo;// �݂������U�����
	KinnikuRun* m_pRun;// �ړ����
	KinnikuJump* m_pJump;// �W�����v���
	KinnikuDead* m_pDead;// ���S���

	// �n���h��
	int m_charHandle;// �L�����N�^�[�S��
	int m_idleHandle;// �A�C�h�����
	int m_jabHandle;// �W���u�U�����
	int m_muscleHandle;// ���؏Ռ��g�U�����
	int m_UpperHandle;// �A�b�p�[�U�����
	int m_MizoHandle;// �݂������U�����
	int m_RunHandle;// �ړ����
	int m_JumpHandle;// �W�����v���
	int m_FallHandle;// �������
	int m_DeadHandle;// ���S���

	// �摜�̍��W
	int m_imgPosX;// X
	int m_imgPosY;// Y

	// �摜�̈�Ђ̒���
	int m_imgWidth;// X
	int m_imgHeight;// Y

	// ���[�V�����I���̃J�E���g
	int m_motionCount;

	// ��������
	int m_initCount;

	// �W�����v�����x
	float m_jumpAcc;

	// �L�����̌���
	bool m_charDirection;

	// �L�������ړ���Ԃ��ǂ���
	bool m_charRun;

	// �L�����̍U������̃^�C�~���O
	bool m_isAttack;

	// �L�������W�����v�����ǂ���
	float m_isJump;

	// �e�X�g�ϐ�
	int m_stiffen = 0;// �d��
};

