#pragma once
#include "../Base/PlayerBase.h"

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
private:
	int m_Handle;
	DinosaurStateManager* m_StateManager;
};

