#include "KinnikuIdle.h"

KinnikuIdle::KinnikuIdle()
{
}

KinnikuIdle::~KinnikuIdle()
{
}

void KinnikuIdle::Init()
{
}

void KinnikuIdle::End()
{
}

void KinnikuIdle::Update(int imagePosX, int imagePosY)
{
	m_frameCount++;
	if (m_frameCount == 3)
	{
		imagePosX++;
		m_frameCount = 0;
	}
	if (imagePosX >= 2)
	{
		imagePosX = 0;
	}
}
