#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMizo : public MoveTypeBase
{
public:
	KinnikuMizo();
	virtual ~KinnikuMizo();

	void Init();
	void End();
	void Update(int imagePosX, int imagePosY);
};

