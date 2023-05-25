#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class SceneMapSelect : public SceneBase
{
public:
	SceneMapSelect();
	virtual ~SceneMapSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	// ステージが選ばれた時の処理
	//bool IsSelected() { return };

private:
};

