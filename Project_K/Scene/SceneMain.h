#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

// |C^
class Dinosaur;		// āĻŪ
class Elf;			// Gt
class Kinnikurou;	// Ø÷
class Witch;		// 
class PlayerBase;
class Collision;

class Stage;		// Xe[W

class SceneMain : public SceneBase
{
public:
	SceneMain(PlayerBase* Player1, PlayerBase* Player2);
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
	Stage*		m_pStage;

	PlayerBase* m_Player[2];

	Collision* m_Coll;

	bool m_isDino;
	bool m_isElf;
	bool m_isKin;
	bool m_isWitch;

	bool m_isVictoryOrDefeat = true;// s:true.1P,false.2P
};


	