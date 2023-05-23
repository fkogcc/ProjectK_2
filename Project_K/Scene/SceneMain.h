#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

// ポインタ
class Dinosaur;		// 爬虫類
class Elf;			// エルフ
class Kinnikurou;	// 筋肉
class Witch;		// 魔女
class PlayerBase;
class Collision;

class Stage;		// ステージ

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
	Stage*		m_pStage;

	PlayerBase* m_Player[2];

	Collision* m_Coll;

	bool m_isDino;
	bool m_isElf;
	bool m_isKin;
	bool m_isWitch;
};


	