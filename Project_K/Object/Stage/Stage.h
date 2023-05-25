#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include<vector>
#include "../Stage/StageBase.h"

namespace
{
	constexpr int kStartX = 0;
	constexpr int kStartY = 700;
	constexpr int kEndX = Game::kScreenWidth;
	constexpr int kEndY = 700;
}

class StageBase;

class Stage : public StageBase
{
public:
	Stage();
	virtual ~Stage();

	void Init();
	void Update();
	void Draw();

	int MapRead();	// csvファイルの読み込み

	int GetStartX() const { return kStartX; }	// 始点座標Xの取得
	int GeStartY() const { return kStartY; }	// 始点座標Yの取得
	int GetEndX() const { return kEndX; }		// 終点座標Xの取得
	int GetEndY() const { return kEndY; }		// 終点座標Yの取得

	struct MapInfo
	{
		Vec2 m_pos;		// マップの座標
		int m_chipNo;	// マップチップの番号
	};

private:
	Vec2 m_pos;

	std::vector<MapInfo> m_data;
};

