#pragma once
#include "SceneBase.h"

class SceneMapSelect : public SceneBase
{
public:
	SceneMapSelect();
	virtual ~SceneMapSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
};

