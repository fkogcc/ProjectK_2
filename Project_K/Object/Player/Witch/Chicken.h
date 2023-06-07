#pragma once
#include "../Base/MoveTypeBase.h"
class Chicken :
	public MoveTypeBase
{
public:
	Chicken();
	virtual ~Chicken();
	void Init();
	void Update();
	void Draw();

	void SetReversal(bool reversal) { m_reversal = reversal; }
	void SetPos(Vec2 pos) { m_pos = pos; }
	void SetFlag(bool flag) { m_exist = flag; }
	bool IsExist() { return m_exist; }
	Vec2 ReturnPos() { return m_pos; }
private:
	int m_handle;
	int m_movePos;
	bool m_reversal;
	Vec2 m_pos;
	int m_animeFrame;
	int m_animeMax;
	int m_animeWidth;
	int m_animeHight;
	bool m_exist;
	int m_countFrame;
};

