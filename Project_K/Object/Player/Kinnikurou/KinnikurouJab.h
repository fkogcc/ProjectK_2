#pragma once
#include "../Base/MoveTypeBase.h"

class KinnikurouJab : public MoveTypeBase
{
public:
	KinnikurouJab();
	virtual ~KinnikurouJab();

	void Init();
	void End();
	void Update(int imagePosX, int imagePosY);

private:

};

