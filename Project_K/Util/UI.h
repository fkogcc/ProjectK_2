#pragma once
#include"Vec2.h"

class UI
{
public:
	UI();
	~UI() {};

	void Init() {}
	void Update();
	void Draw();

private:

	Vec2 m_boxPos;

	struct  UIData
	{
		Vec2 m_pos = { 0,0 };
		int m_life = 0;
		int m_damage = 0;
		int m_empty = 0;
	};

	int m_countFrame;


	UIData UI1;
	UIData UI2;
};
