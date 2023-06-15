#include "StageBase.h"
#include "../../Util/game.h"

StageBase::StageBase():
	m_handle(-1),
	m_bgHandle(-1),
	m_startX(0),
	m_startY(700),
	m_endX(Game::kScreenWidth),
	m_endY(0)
{
}

StageBase::~StageBase()
{
}

void StageBase::Init()
{
}

void StageBase::Update()
{
}

void StageBase::Draw()
{
}
