#pragma once
#include"Vec2.h"

class UI
{
public:
	UI(int Hp1, int Hp2);
	~UI() {};

	void Init() {}// ������
	void Update();// �X�V����
	void Draw();// �`�揈��

	void HpUpdate();
	void HpDraw();

	void FontUpdate();
	void FontDraw();


	void GetHp1(int hp) { UI1.m_temp = hp; }// 1P��HP
	void GetHp2(int hp) { UI2.m_temp = hp; }// 2P��HP
	void AttackFlag(bool flag) { m_attackFlag = flag; }
private:

	Vec2 m_boxPos;

	struct  UIData
	{
		Vec2 m_pos = { 0,0 };// HP�o�[�̈ʒu
		int m_temp = 0;// HP�������Ƃ�p�̕ϐ�
		int m_life = 0;// �e�v���C���[��HP
		int m_lower = 0;// ���ŕۑ�����HP�p�̕ϐ�
	};

	int m_countFrame;// ����HP�����炷�^�C�}�[

	bool m_attackFlag;
	UIData UI1;
	UIData UI2;
};
