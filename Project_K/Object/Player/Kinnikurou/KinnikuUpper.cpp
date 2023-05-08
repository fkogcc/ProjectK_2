#include "KinnikuUpper.h"

void KinnikuUpper::Update(int& imagePosX, int& imagePosY)
{
	m_frameCount++;
	if (m_frameCount == 10)
	{
		imagePosX++;
		m_frameCount = 0;

	}
	if (imagePosX >= 4)
	{
		imagePosX = 0;
	}
}
