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
	SceneMain(PlayerBase* Player1, PlayerBase* Player2);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	Stage*		m_pStage;

	PlayerBase* m_Player[2];

	Collision* m_Coll;

	bool m_isVictory1P;// 1Pの勝敗
	bool m_isVictory2P;// 2Pの勝敗
};


	