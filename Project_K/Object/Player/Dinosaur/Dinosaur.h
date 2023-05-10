#pragma once
#include "../Base/PlayerBase.h"
#include<vector>

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
	void Draw();// �`��

	void GetAttackSize();
private:
	int m_Handle;
	DinosaurStateManager* m_StateManager;

	std::vector<ShotBase*> m_Shot;
};

