#pragma once
#include "../Base/MoveTypeBase.h"
class KnightCat :
    public MoveTypeBase
{
public:
	KnightCat();
	virtual ~KnightCat();
	void Init();
	void Update();
	void Draw();

	void SetReversal(bool reversal) { m_reversal = reversal; }
	void SetPos(Vec2 pos);
	void SetFlag(bool flag) { m_exist = flag; }
	bool IsExist() { return m_exist; }
private:
	int m_handle;
	bool m_reversal;
	Vec2 m_pos;
	int m_timeCount;
	int m_animeFrame;
	int m_animeMax;
	int m_animeWidth;
	int m_animeHight;
	bool m_exist;
};
