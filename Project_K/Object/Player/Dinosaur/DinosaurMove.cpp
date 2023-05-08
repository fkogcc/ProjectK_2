#include "DinosaurMove.h"
#include "DinosaurStateBase.h"
#include <DxLib.h>
#include "DinosaurIdle.h"
#include"DinosaurJump.h"

namespace
{
	constexpr float kMoveSpeed = 5.0f;
}


DinosaurMove::~DinosaurMove()
{
}

void DinosaurMove::IsMove()
{
	m_Vec.x = 0;
	if (Pad::isPress(PAD_INPUT_LEFT))// XBOX X or Y
	{
		m_Vec.x = -kMoveSpeed;
	}

	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		m_Vec.x = kMoveSpeed;
	}
}

DinosaurStateBase* DinosaurMove::Update()
{
	ChangeGraph(3, 6, true);

	IsMove();

	m_Pos.x += m_Vec.x;

	if (Pad::isPress(PAD_INPUT_UP))// XBOX X or Y
	{
		return new DinosaurJump(m_Pos,m_Vec);
	}

	if (m_Vec.x != 0)	// キャラクターが動いているとき
	{
		return this;
	}

	return new DinosaurIdle(m_Pos,m_Vec);
}
