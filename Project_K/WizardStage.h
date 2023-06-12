#pragma once
#include "../../Util/Vec2.h"
#include "../../Util/game.h"
#include<vector>

namespace
{
	constexpr int kStartX = 0;
	constexpr int kStartY = 700;
	constexpr int kEndX = Game::kScreenWidth;
	constexpr int kEndY = 700;
}

class WizardStage
{
public:
	WizardStage();
	virtual ~WizardStage();

	void Init();
	void Update();
	void Draw();

	int MapRead();	// csvファイルの読み込み

	int GetStartX() const { return kStartX; }	// 始点座標Xの取得
	int GeStartY() const { return kStartY; }	// 始点座標Yの取得
	int GetEndX() const { return kEndX; }		// 終点座標Xの取得
	int GetEndY() const { return kEndY; }		// 終点座標Yの取得

	// 外部からのステージセレクト番号のsetter
	int const GetSelectNum() const { m_selectNum; }

	struct MapInfo
	{
		Vec2 m_pos;		// マップの座標
		int m_chipNo;	// マップチップの番号
	};

private:
	Vec2 m_pos;
	int m_handle;	// グラフィックハンドル
	int m_bgHandle;	// 背景用グラフィックハンドル

	int m_selectNum;	// 外部からのint型数値を格納するための変数

	std::vector<MapInfo> m_data;// vector型の2次元配列変数
};

