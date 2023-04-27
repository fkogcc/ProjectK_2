#pragma once

#include "../Base/MoveTypeBase.h"

class KinnnikuIdle : public MoveTypeBase
{
public:
	KinnnikuIdle();
	virtual ~KinnnikuIdle();

	void Init();// ‰Šú‰»
	void End();// I—¹
	void Update(int imagePosX, int imagePosY);// XV

private:
};

