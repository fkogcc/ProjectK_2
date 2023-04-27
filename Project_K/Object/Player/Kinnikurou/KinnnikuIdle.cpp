#include "KinnnikuIdle.h"

KinnnikuIdle::KinnnikuIdle()
{
}

KinnnikuIdle::~KinnnikuIdle()
{
}

void KinnnikuIdle::Init()
{
}

void KinnnikuIdle::End()
{
}

void KinnnikuIdle::Update(int imagePosX, int imagePosY)
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
