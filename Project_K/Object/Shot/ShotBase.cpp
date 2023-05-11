#include "ShotBase.h"
#include <DxLib.h>
//#include"game.h"

ShotBase::~ShotBase()
{
}

void ShotBase::Update()
{
	if (!IsExist())
	{
		m_Exist = false;
	}
}

void ShotBase::Draw()
{
	DrawCircle(m_Shot.Pos.x, m_Shot.Pos.y, 50,
		0xffffff, true);

	DrawBox(m_Shot.Pos.x + m_Shot.shotSizeLeft, m_Shot.Pos.y + m_Shot.shotSizeTop,
		m_Shot.Pos.x + m_Shot.shotSizeRight, m_Shot.Pos.y + m_Shot.shotSizeBottom,
		0xff0000, false);
}


bool ShotBase::IsExist()
{

	// ‰æ–ÊŠO‚Éo‚½Žž‚Ìˆ—
	if (m_Shot.Pos.y > Game::kScreenHeight) return false;
	if (m_Shot.Pos.y < 0) return false;
	if (m_Shot.Pos.x > Game::kScreenWidth) return false;
	if (m_Shot.Pos.x < 0) return false;

	return true;
}
