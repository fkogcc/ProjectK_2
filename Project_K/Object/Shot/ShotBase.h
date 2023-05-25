#pragma once
#include"../../Util/Vec2.h"
#include"../../Util/game.h"
class ShotBase
{
protected:
	struct Data
	{
		Vec2 Pos;
		Vec2 Vec;

		int shotSizeLeft = 0;
		int shotSizeTop = 0;
		int shotSizeRight = 0;
		int shotSizeBottom = 0;
	};

	Data m_Shot;

	bool m_Exist = false; // ���݂��邩�ǂ���
	bool m_NullShot = false;	  // NullShot�ł��邩�ǂ���
public:
	ShotBase();

	virtual ~ShotBase();

	virtual void Update();
	virtual void Draw();

	virtual Vec2 GetPos() { return m_Shot.Pos; }
	virtual int GetSizeLeft() { return m_Shot.shotSizeLeft; }
	virtual int GetSizeTop() { return m_Shot.shotSizeTop; }
	virtual int GetSizeRight() { return m_Shot.shotSizeRight; }
	virtual int GetSizeBottom() { return m_Shot.shotSizeBottom; }

	virtual bool IsExist();

	virtual bool GetExist() { return m_Exist; }

	virtual bool GetNullShot() { return m_NullShot; }
};

