#pragma once
#include "SceneBase.h"

class SceneCharacterSelect : public SceneBase
{
public:
	SceneCharacterSelect();
	virtual ~SceneCharacterSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
};

