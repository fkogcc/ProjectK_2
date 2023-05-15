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

	ShotBase* GetShot(int i);
private:
	int m_Handle;
	DinosaurStateManager* m_StateManager;

	bool m_LookRight;	// �E�����Ă�Ƃ�
};

