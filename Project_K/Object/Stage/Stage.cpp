#include "Stage.h"
#include <Dxlib.h>
#include "../../Util/game.h"

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
}

void Stage::Update()
{
}

void Stage::Draw()
{
	DrawExtendGraph(kStartX, kStartY, Game::kScreenWidth, kStartY * 2, m_handle, true);
	DrawLine(kStartX, kStartY, kEndX, kEndY, 0xffffff);
}
