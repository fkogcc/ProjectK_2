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

	void Init();// ‰Šú‰»
	void End();// I—¹ˆ—
	void Update();// XV
	void Draw()override;// •`‰æ

	void GetAttackSize();

	void SetAttackFlag(bool attackFlag)override;
private:
	int m_handle;
	DinosaurStateManager* m_pStateManager;
};

