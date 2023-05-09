#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

class Dinosaur;
class Elf;
class Kinnikurou;
class Witch;

class Stage;

class SceneMain : public SceneBase
{
public:
	SceneMain(bool isDino, bool isElf, bool isKin, bool isWitch);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	Dinosaur*	m_pDino;
	Elf*		m_pElf;
	Kinnikurou* m_pKin;
	Witch*		m_pWitch;

	bool m_isDino;
	bool m_isElf;
	bool m_isKin;
	bool m_isWitch;
};


	