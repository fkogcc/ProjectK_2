#include "KinnikuDead.h"

KinnikuDead::KinnikuDead()
{
}

KinnikuDead::~KinnikuDead()
{
}

void KinnikuDead::Update(int& imagePosX, int& imagePosY)
{
	m_frameCount++;

	if (m_frameCount == 3)
	{
		imagePosX++;
		m_frameCount = 0;
	}
	if (imagePosX>=3) 
	{
		imagePosX = 0;
		imagePosY++;
	}
	if (imagePosX >= 3 && imagePosY <= 4)
	{
		imagePosX = 2;
		imagePosY = 3;
	}
}
