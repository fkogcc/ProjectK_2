#pragma once

class PlayerBase;

class Collision
{
public:
	Collision(PlayerBase* Player1, PlayerBase* Player2);
	virtual ~Collision();

	bool IsColl1();

	bool IsColl2();

	bool ShotColl1();

	bool ShotColl2();

private:
	PlayerBase* m_Player[2];
};

