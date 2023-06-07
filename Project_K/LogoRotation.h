#pragma once

#include "Util/Vec2.h"

class LogoRotation
{
public:
	LogoRotation();
	virtual ~LogoRotation();

	void Init();
	void Update();
	void Draw();
private:
	// 
	int m_hLogo;

	Vec2 m_pos;
	Vec2 m_logoPos;

	bool m_isTrans;

	int width, height;
};

