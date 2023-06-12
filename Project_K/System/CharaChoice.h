#pragma once
#include<DxLib.h>

namespace
{
	constexpr int kCharaNum = 4; //�L�����N�^�[�̐�
}

class CharaChoice
{
public:
	CharaChoice();
	virtual ~CharaChoice();

	void Init();
	void Update();
	void Draw();

	//�L�����i���o�[��Ԃ�
	int GetChackChara1() { return m_charaNumber1; }
	int GetChackChara2() { return m_charaNumber2; }

	//�L�����N�^�[�������Ԃ�.
	bool GetDecision1() { return m_Decision1; }
	bool GetDecision2() { return m_Decision2; }

private:
	//�L�����i���o�[�̃A�b�v�f�[�g
	void updateChara1();
	void updateChara2();

	// �L�����i���o�[(0:���� 1:����ɌN2:�G���t3:����)
	int m_charaNumber1;
	int m_charaNumber2;

	
	bool m_Decision1;// �L�����N�^�[1�����肳�ꂽ��
	bool m_Decision2;// �L�����N�^�[2�����肳�ꂽ��
};