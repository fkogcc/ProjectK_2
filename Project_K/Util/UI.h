#pragma once
#include"Vec2.h"

class UI
{
public:
	UI();
	~UI() {};

	void Init() {}// ������
	void Update();// �X�V����
	void Draw();// �`�揈��

	void GetHp1(int hp) { UI1.m_life = hp; }// 1P��HP
	void GetHp2(int hp) { UI2.m_life = hp; }// 2P��HP
private:

	Vec2 m_boxPos;

	struct  UIData
	{
		Vec2 m_pos = { 0,0 };// HP�o�[�̈ʒu
		int m_life = 0;// �e�v���C���[��HP
		int m_temp = 0;// ���ŕۑ�����HP�p�̕ϐ�
	};

	int m_countFrame;// ����HP�����炷�^�C�}�[


	UIData UI1;
	UIData UI2;
};
