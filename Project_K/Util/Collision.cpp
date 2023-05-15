#include "Collision.h"

Collision::Collision(PlayerBase* Player1, PlayerBase* Player2)
{
	m_Player[0] = Player1;
	m_Player[1] = Player2;
}

Collision::~Collision()
{
}

bool Collision::IsColl1()
{

	return false;
}

bool Collision::IsColl2()
{
	return false;
}

