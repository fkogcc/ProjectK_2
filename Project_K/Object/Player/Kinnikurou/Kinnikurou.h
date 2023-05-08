#pragma once

#include "../Base/PlayerBase.h"

class KinnikuIdle;
class KinnikurouJab;
class KinnikuMuscle;
class KinnikuUpper;
class KinnikuMizo;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// ������
	void End   ();// �I������
	void Update();// �X�V
	void Draw  ();// �`��
private:

	KinnikuIdle* m_pIdle;
	KinnikurouJab* m_pJab;
	KinnikuMuscle* m_pMuscle;
	KinnikuUpper* m_pUpper;
	KinnikuMizo* m_pMizo;

	bool m_pushBottom;

	// �n���h��
	int m_charHandle;// �L�����N�^�[�S��
	int m_idleHandle;// �A�C�h�����
	int m_jabHandle;// �W���u�U�����
	int m_muscleHandle;// �}�b�X���U�����
	int m_UpperHandle;// �A�b�p�[�U�����
	int m_MizoHandle;// �݂������U�����

	// �`����W
	int m_drawPosX;// X
	int m_drawPosY;// Y

	// �摜�̍��W
	int m_imgPosX;// X
	int m_imgPosY;// Y

	// �摜�̈�Ђ̒���
	int m_imgWidth;// X
	int m_imgHeight;// Y
};
