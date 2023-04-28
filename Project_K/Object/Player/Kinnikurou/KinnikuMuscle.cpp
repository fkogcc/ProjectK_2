#include "KinnikuMuscle.h"

KinnikuMuscle::KinnikuMuscle()
{
}

KinnikuMuscle::~KinnikuMuscle()
{
}

void KinnikuMuscle::Init()
{
}

void KinnikuMuscle::End()
{
}

void KinnikuMuscle::Update(int imagePosX, int imagePosY)
{
	m_frameCount++;
	if (m_frameCount == 3)
	{
		imagePosX++;
		m_frameCount = 0;

	}
	if (imagePosX >= 4)
	{
		imagePosX = 0;
		imagePosY++;
	}
	if (imagePosX >= 3 || imagePosY >= 2)
	{
		imagePosX = 0;
		imagePosY = 0;
	}

}