#include "Stage.h"
#include <Dxlib.h>
#include "../../Util/game.h"

Stage::Stage() : 
	m_pos(0, 700)
{
}

Stage::~Stage()
{
}

void Stage::Init()
{
}

void Stage::Update()
{
}

void Stage::Draw()
{
	DrawLine(kStartX, kStartY, kEndX, kEndY, 0xffffff);
}
