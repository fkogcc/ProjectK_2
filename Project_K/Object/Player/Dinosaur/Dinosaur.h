#pragma once
#include "../Base/PlayerBase.h"
#include<array>

class ShotBase;
class DinosaurStateManager;

class Dinosaur : public PlayerBase
{
public:
	Dinosaur();
	~Dinosaur();

	void Init();// ������
	void End();// �I������
	void Update();// �X�V
	void Draw()override;// �`��

	void GetAttackSize();

	void SetAttackFlag(bool attackFlag)override;
private:
	int m_handle; //�v���C���[�n���h��
	int m_shotHandle;//�V���b�g�n���h��
	DinosaurStateManager* m_pStateManager;
};

