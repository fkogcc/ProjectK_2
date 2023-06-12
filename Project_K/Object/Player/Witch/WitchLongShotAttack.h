#pragma once
#include "../Base/MoveTypeBase.h"
class WitchLongShotAttack :
    public MoveTypeBase
{
public:
	WitchLongShotAttack();// �R���X�g���N�^
	virtual ~WitchLongShotAttack() {}// �f�X�g���N�^

	void Init();// ������
	void Update();// �X�V����

	int IndexX() { return m_animeWidth; }// �A�j���[�V�����̃Z�b�g�p
	int IndexY() { return m_animeHight; }// �A�j���[�V�����̃Z�b�g�p
	int SizeX() { return m_indexX; }// �T�C�Y�ύX
	int ShiftX() { return m_shiftX; }// ���炵�悤
	int AnimeMax() { return m_animeMax; }// �A�j���[�V�����̃Z�b�g�p
	void SetReversal(bool reversal) { m_reversal = reversal; }// ���]
private:
	int m_animeWidth;// ��
	int m_animeHight;// �c
	int m_animeMax;//����
	int m_indexX;// �T�C�Y
	int m_shiftX;// ���炷
	bool m_reversal;// ���]
};

