#include "KinnikuMizo.h"

void KinnikuMizo::Update(int& imagePosX, int& imagePosY)
{
	m_isAttackCol = false;
	m_frameCount++;

	if (imagePosX == 0 && imagePosY == 0)
	{
		m_nextCount = 20;
	}
	else if (imagePosX == 3 && imagePosY == 0)
	{
		m_nextCount = 10;
	}
	else
	{
		m_nextCount = 2;
	}

	if (m_frameCount == m_nextCount)
	{
		imagePosX++;
		m_frameCount = 0;

	}
	if (imagePosX >= 4)
	{
		imagePosX = 0;
	}
	if (imagePosX == 2 && imagePosY == 0)
	{
		m_isAttackCol = true;
	}
}
