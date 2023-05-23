#pragma once

#include "../Base/PlayerBase.h"

class KinnikuIdle;
class KinnikurouJab;
class KinnikuMuscle;
class KinnikuUpper;
class KinnikuMizo;
class KinnikuRun;
class KinnikuJump;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// ������
	void End   ();// �I������
	void Update();// �X�V
	void Draw()override;// �`��

	void ImgposInit();

private:

	KinnikuIdle* m_pIdle;
	KinnikurouJab* m_pJab;
	KinnikuMuscle* m_pMuscle;
	KinnikuUpper* m_pUpper;
	KinnikuMizo* m_pMizo;
	KinnikuRun* m_pRun;
	KinnikuJump* m_pJump;

	bool m_pushBottom;

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

	// �L�������W�����v�����ǂ���
	float m_isJump;
};

