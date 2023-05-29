#include "Collision.h"
#include"../Object/Player/Dinosaur/Dinosaur.h"
#include"../Object/Player/Kinnikurou/Kinnikurou.h"
#include<cassert>

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
	if (!m_Player[1]->GetAttackFlag())
	{
		return false;
	}

	int PlayerLeft = static_cast<int>(m_Player[0]->GetPos().x) + m_Player[0]->GetSizeLeft();
	int PlayerTop = static_cast<int>(m_Player[0]->GetPos().y) + m_Player[0]->GetSizeTop();
	int PlayerRight = static_cast<int>(m_Player[0]->GetPos().x) + m_Player[0]->GetSizeRight();
	int PlayerBottom = static_cast<int>(m_Player[0]->GetPos().y) + m_Player[0]->GetSizeBottom();

	int PlayerAtkLeft = static_cast<int>(m_Player[1]->GetPos().x) + m_Player[1]->GetAttackSizeLeft();
	int PlayerAtkTop = static_cast<int>(m_Player[1]->GetPos().y) + m_Player[1]->GetAttackSizeTop();
	int PlayerAtkRight = static_cast<int>(m_Player[1]->GetPos().x) + m_Player[1]->GetAttackSizeRight();
	int PlayerAtkBottom = static_cast<int>(m_Player[1]->GetPos().y) + m_Player[1]->GetAttackSizeBottom();

	if (PlayerLeft > PlayerAtkRight) return false;
	if (PlayerRight < PlayerAtkLeft) return false;
	if (PlayerTop > PlayerAtkBottom) return false;
	if (PlayerBottom < PlayerAtkTop)return false;

	
	
	return true;
}

bool Collision::IsColl2()
{
	if (!m_Player[0]->GetAttackFlag())
	{
		return false;
	}

	int PlayerLeft = static_cast<int>(m_Player[1]->GetPos().x) + m_Player[1]->GetSizeLeft();
	int PlayerTop = static_cast<int>(m_Player[1]->GetPos().y) + m_Player[1]->GetSizeTop();
	int PlayerRight = static_cast<int>(m_Player[1]->GetPos().x) + m_Player[1]->GetSizeRight();
	int PlayerBottom = static_cast<int>(m_Player[1]->GetPos().y) + m_Player[1]->GetSizeBottom();

	int PlayerAtkLeft = static_cast<int>(m_Player[0]->GetPos().x) + m_Player[0]->GetAttackSizeLeft();
	int PlayerAtkTop = static_cast<int>(m_Player[0]->GetPos().y) + m_Player[0]->GetAttackSizeTop();
	int PlayerAtkRight = static_cast<int>(m_Player[0]->GetPos().x) + m_Player[0]->GetAttackSizeRight();
	int PlayerAtkBottom = static_cast<int>(m_Player[0]->GetPos().y) + m_Player[0]->GetAttackSizeBottom();

	if (PlayerLeft > PlayerAtkRight) return false;
	if (PlayerRight < PlayerAtkLeft) return false;
	if (PlayerTop > PlayerAtkBottom) return false;
	if (PlayerBottom < PlayerAtkTop)return false;



	return true;
}

