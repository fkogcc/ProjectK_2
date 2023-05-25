#include "DinosaurStateBase.h"
#include"DxLib.h"
#include "../../../Util/DrawFunctions.h"

namespace
{
	constexpr int kGraphSizeX = 640;
	constexpr int kGraphSizeY = 640;
}

void DinosaurStateBase::Init(int Handle)
{
	m_Handle = Handle;
}

void DinosaurStateBase::Draw(int handle , bool lookRight)
{
	my::MyDrawRectRotaGraph(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y), 640 * m_imagePosX, 220 * m_imagePosY,
		640, 220, 1, 0, handle, true, lookRight);
}

void DinosaurStateBase::ChangeGraph(int ChangeSpeed, int GraphNum, bool ChangeY)
{
	m_frameCount++;

	if (m_frameCount > ChangeSpeed)
	{
		m_frameCount = 0;
		m_imagePosX++;

		if (m_imagePosX >= GraphNum)
		{
			m_imagePosX = 0;

			if (ChangeY)
			{
				if (m_imagePosY == 0)
				{
					m_imagePosY = 1;
					return;
				}

				if (m_imagePosY == 1)
				{
					m_imagePosY = 0;
					return;
				}
			}
		}
	}
}
