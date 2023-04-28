#include "KinnikuMizo.h"

KinnikuMizo::KinnikuMizo()
{
}

KinnikuMizo::~KinnikuMizo()
{
}

void KinnikuMizo::Init()
{
}

void KinnikuMizo::End()
{
}

void KinnikuMizo::Update(int imagePosX, int imagePosY)
{
	m_frameCount++;
	if (m_frameCount == 4)
	{
		imagePosX++;
		m_frameCount = 0;

	}
	if (imagePosX >= 4)
	{
		imagePosX = 0;
	}
}
