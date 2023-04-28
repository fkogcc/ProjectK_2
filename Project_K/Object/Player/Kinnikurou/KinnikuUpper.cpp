#include "KinnikuUpper.h"

KinnikuUpper::KinnikuUpper()
{
}

KinnikuUpper::~KinnikuUpper()
{
}

void KinnikuUpper::Init()
{
}

void KinnikuUpper::End()
{
}

void KinnikuUpper::Update(int imagePosX, int imagePosY)
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
