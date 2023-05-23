#include "KinnikuMuscle.h"

void KinnikuMuscle::Update(int& imagePosX, int& imagePosY)
{
	m_isAttackCol = false;
	m_frameCount++;
	if (m_frameCount == 10)
	{
		imagePosX++;
		m_frameCount = 0;

	}
	if (imagePosX >= 4)
	{
		imagePosX = 0;
		imagePosY++;
	}
	if (imagePosX >= 3 && imagePosY >= 1)
	{
		imagePosX = 0;
		imagePosY = 0;
	}
	if (imagePosX == 3 && imagePosY == 0)
	{
		m_isAttackCol = true;
	}
}
