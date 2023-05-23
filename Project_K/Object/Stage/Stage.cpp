#include<vector>
#include<iostream>
#include<cassert>
#include "Stage.h"
#include <Dxlib.h>
#include "../../Util/game.h"

namespace
{
	constexpr int kMapDataHeight = 17;
	constexpr int kMapDataWidth = 30;

	constexpr int kMapData[kMapDataHeight][kMapDataWidth] =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,14,14,4,3,4,5,6,7,8,9,10,11,12,13,14,14},
		{ 17,18,19,20,21,22,23,24,25,26,27,28,29,30,30,30,20,19,20,21,22,23,24,25,26,27,28,29,30,30},
		{ 68,69,84,85,86,87,88,89,90,91,92,93,118,91,92,93,118,83,84,85,86,87,88,89,90,91,92,93,68,69},
		{ 84,85,211,212,213,214,215,216,217,218,219,220,221,69,211,212,69,211,212,213,214,215,216,217,218,219,220,221,84,85},
		{ 211,212,213,214,215,216,217,218,219,220,221,211,212,213,214,215,216,217,218,211,212,213,214,215,216,217,218,219,220,221},
		{ 211,212,213,214,215,216,217,218,219,220,221,211,212,213,214,215,216,217,218,211,212,213,214,215,216,217,218,219,220,221},

	};
}

Stage::Stage() : 
	m_pos(0, 700),
	m_handle(-1)
{
}

Stage::~Stage()
{
}

void Stage::Init()
{
	m_handle = LoadGraph("Data/Image/Stage/WizardMap.png");

	for (int i = 0; i < kMapDataWidth; i++)
	{
		for (int j = 0; j < kMapDataHeight; j++)
		{

			m_data.push_back(kMapData[i][j]);

		}
	}

}

void Stage::Update()
{

}

void Stage::Draw()
{
	DrawExtendGraph(kStartX, kStartY, Game::kScreenWidth, kStartY * 2, m_handle, true);
	DrawLine(kStartX, kStartY, kEndX, kEndY, 0xffffff);
}
