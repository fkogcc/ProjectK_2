#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

class Elf;

class Kinnikurou;

class Stage;

class SceneMain : public SceneBase
{
public:
	SceneMain(bool player1, bool player2, bool player3, bool player4);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	Elf* m_pElf;
};


	