#pragma once
#include "../Base/MoveTypeBase.h"
class WitchShotAttack :
    public MoveTypeBase
{
public:
	WitchShotAttack();// �R���X�g���N�^
	virtual ~WitchShotAttack() {}// �f�X�g���N�^

	void Init();// ������

	int IndexX() { return m_animeWidth; }// �A�j���[�V�����̃Z�b�g�p
	int IndexY() { return m_animeHight; }// �A�j���[�V�����̃Z�b�g�p
	int AnimeMax() { return m_animeMax; }// �A�j���[�V�����̃Z�b�g�p
private:
	int m_animeWidth;// ��
	int m_animeHight;// �c
	int m_animeMax;//����
};

