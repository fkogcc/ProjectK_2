#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikuMuscle : public MoveTypeBase
{
public:
	KinnikuMuscle();
	virtual ~KinnikuMuscle();

	void Init();
	void End();
	void Update(int imagePosX, int imagePosY);
};

