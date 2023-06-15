#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include "../Stage/StageBase.h"
#include<vector>

class DinoStage : public StageBase
{
public:
	DinoStage();

	void Init();
	void Update();
	void Draw();

	int MapRead();	// csvファイルの読み込み

	struct MapInfo
	{
		Vec2 m_pos;		// マップの座標
		int m_chipNo;	// マップチップの番号
	};

private:
	Vec2 m_pos;

	std::vector<MapInfo> m_data;// vector型の2次元配列変数
};

