#include "DinosaurStateBase.h"
#include"DxLib.h"
#include "../../../Util/DrawFunctions.cpp"

namespace
{
	constexpr int kGraphSizeX = 640;
	constexpr int kGraphSizeY = 640;
}

void DinosaurStateBase::Init(int Handle)
{
	m_Handle = Handle;
}

void DinosaurStateBase::Draw()
{
	my::MyDrawRectRotaGraph(m_Pos.x, m_Pos.y, m_Pos.x - 320, m_Pos.y - 110,
		m_Pos.x + 320, m_Pos.y + 110, 1, 0, m_Handle, true, false);
}
