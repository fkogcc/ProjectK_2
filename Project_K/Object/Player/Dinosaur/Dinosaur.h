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

	void Init();// ‰Šú‰»
	void End();// I—¹ˆ—
	void Update();// XV
	void Draw();// •`‰æ

	void GetAttackSize();
private:
	int m_Handle;
	DinosaurStateManager* m_StateManager;

	std::vector<ShotBase*> m_Shot;
};

