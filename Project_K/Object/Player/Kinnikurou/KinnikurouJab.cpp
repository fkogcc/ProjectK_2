#include "KinnikurouJab.h"

KinnikurouJab::KinnikurouJab()
{
}

KinnikurouJab::~KinnikurouJab()
{
}

void KinnikurouJab::Init()
{
}

void KinnikurouJab::End()
{
}

void KinnikurouJab::Update(int imagePosX, int imagePosY)
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

void KinnikurouJab::Draw()
{
}
