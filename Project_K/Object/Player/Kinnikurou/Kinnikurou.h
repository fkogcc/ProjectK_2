#pragma once

#include "../Base/PlayerBase.h"

class KinnikuIdle;
class KinnikurouJab;
class KinnikuMuscle;
class KinnikuUpper;
class KinnikuMizo;
class KinnikuRun;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// ������
	void End   ();// �I������
	void Update();// �X�V
	void Draw  ();// �`��

	void ImgposInit();

private:

	KinnikuIdle* m_pIdle;
	KinnikurouJab* m_pJab;
	KinnikuMuscle* m_pMuscle;
	KinnikuUpper* m_pUpper;
	KinnikuMizo* m_pMizo;
	KinnikuRun* m_pRun;

	bool m_pushBottom;

	// �n���h��
	int m_charHandle;// �L�����N�^�[�S��
	int m_idleHandle;// �A�C�h�����
	int m_jabHandle;// �W���u�U�����
	int m_muscleHandle;// �}�b�X���U�����
	int m_UpperHandle;// �A�b�p�[�U�����
	int m_MizoHandle;// �݂������U�����
	int m_RunHandle;//�ړ����

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

	// �L�����̌���
	bool m_charDirection;

	// �L�������ړ���Ԃ��ǂ���
	bool m_charRun;
};

