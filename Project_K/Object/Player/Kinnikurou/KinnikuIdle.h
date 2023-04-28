#pragma once

#include "../Base/MoveTypeBase.h"

class KinnikuIdle : public MoveTypeBase
{
public:
	KinnikuIdle();
	virtual ~KinnikuIdle();

	void Init();// ‰Šú‰»
	void End();// I—¹
	void Update(int imagePosX, int imagePosY);// XV

private:
};

