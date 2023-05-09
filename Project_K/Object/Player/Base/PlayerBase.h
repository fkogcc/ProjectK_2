#pragma once
#include <DxLib.h>
#include "../../Util/Pad.h"
#include "../../Util/Vec2.h"

class PlayerBase //�v���C���[�̊��N���X
{
public:
	PlayerBase() {};
	virtual ~PlayerBase() {};

	virtual void Init  () {};// ������
	virtual void End   () {};// �I������
	virtual void Update() {};// �X�V
	virtual void Draw  () {};// �`��
	
	int GetAttackSizeLeft() { return m_attackSizeLeft; }
	int GetAttackSizeTop() { return m_attackSizeTop; }
	int GetAttackSizeRight() { return m_attackSizeRight; }
	int GetAttackSizeBottom() { return m_attackSizeBottom; }

	int SetMove() { return m_moveType; }// SceneMain�ɂǂ̍U�������Ă��邩��n��
	void GetMove(int check) { m_moveType = check; }// SceneMain����U����Ԃ��󂯎��
	void GetDamage(int damage) { m_damage = damage; }// SceneMain����v���C���[���󂯂�_���[�W���󂯎��

	Vec2 SetPos() { return m_pos; }

protected:
	int m_attackSizeLeft = 0;
	int m_attackSizeTop = 0;
	int m_attackSizeRight = 0;
	int m_attackSizeBottom = 0;

	int m_moveType = 0;
	int m_hp     = 100;// �v���C���[�̗̑͗�(100���W��)
	int m_damage = 10; // �v���C���[���󂯂�_���[�W

	bool m_attackFlag = false;// �U�������ǂ���

	Vec2 m_pos = { 0.0f,0.0f };// �ʒu
	Vec2 m_vec = { 0.0f,0.0f };// �^����
};

