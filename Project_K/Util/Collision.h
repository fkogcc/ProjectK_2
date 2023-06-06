#pragma once

class PlayerBase;

class Collision
{
public:
	Collision(PlayerBase* Player1, PlayerBase* Player2);
	virtual ~Collision();

	bool IsColl1();		//�v���C���[1�̍U�����v���C���[2�ɓ���������

	bool IsColl2();		//�v���C���[2�̍U�����v���C���[1�ɓ���������

	bool ShotColl1();	//�v���C���[1�̃V���b�g���v���C���[2�ɓ���������

	bool ShotColl2();	//�v���C���[2�̃V���b�g���v���C���[1�ɓ���������

	bool AttackColl();	//�v���C���[�̍U�����m������������

private:
	PlayerBase* m_Player[2];
};

