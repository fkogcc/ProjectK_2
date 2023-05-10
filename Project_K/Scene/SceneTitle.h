#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	bool m_isFadeOut;// フェードアウトして言るかどうか

};

