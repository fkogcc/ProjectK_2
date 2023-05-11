#pragma once
#include <DxLib.h>
#include "../../Util/Pad.h"
#include "../../Util/Vec2.h"
#include<array>

class ShotBase;
class ShotNull;

namespace
{
	constexpr int kShotMax = 4;	// �V���b�g���ő�
}

class PlayerBase //�v���C���[�̊��N���X
{
public:
	PlayerBase();
	
	virtual ~PlayerBase() {};

	virtual void Init  () {};// ������
	virtual void End   () {};// �I������
	virtual void Update() {};// �X�V
	virtual void Draw  () {};// �`��

	// �v���C���[�̃T�C�Y�擾
	int GetAttackSizeLeft() { return m_sizeLeft; }
	int GetAttackSizeTop() { return m_sizeTop; }
	int GetAttackSizeRight() { return m_sizeRight; }
	int GetAttackSizeBottom() { return m_sizeBottom; }
	
	// �v���C���[�̍U������擾�擾
	int GetSizeAttackLeft() { return m_sizeLeftAttack; }
	int GetSizeAttackTop() { return m_sizeTopAttack; }
	int GetSizeAttackRight() { return m_sizeRightAttack; }
	int GetSizeAttackBottom() { return m_sizeBottomAttack; }

	int SetMove() { return m_moveType; }// SceneMain�ɂǂ̍U�������Ă��邩��n��
	void GetMove(int check) { m_moveType = check; }// SceneMain����U����Ԃ��󂯎��
	void GetDamage(int damage) { m_damage = damage; }// SceneMain����v���C���[���󂯂�_���[�W���󂯎��

	Vec2 SetPos() { return m_pos; }

protected:
	int m_sizeLeft = 0;
	int m_sizeTop = 0;
	int m_sizeRight = 0;
	int m_sizeBottom = 0;

	int m_sizeLeftAttack = 0;
	int m_sizeTopAttack = 0;
	int m_sizeRightAttack = 0;
	int m_sizeBottomAttack = 0;

	int m_moveType = 0;
	int m_hp     = 100;// �v���C���[�̗̑͗�(100���W��)
	int m_damage = 10; // �v���C���[���󂯂�_���[�W

	bool m_attackFlag = false;// �U�������ǂ���

	Vec2 m_pos = { 0.0f,0.0f };// �ʒu
	Vec2 m_vec = { 0.0f,0.0f };// �^����

	std::array<ShotBase*, kShotMax> m_Shot;
};

