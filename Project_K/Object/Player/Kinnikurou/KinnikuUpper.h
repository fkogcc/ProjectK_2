#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuUpper : public MoveTypeBase
{
public:
	KinnikuUpper();
	virtual ~KinnikuUpper();

	void Init();
	void End();
	void Update(int imagePosX, int imagePosY);
};

