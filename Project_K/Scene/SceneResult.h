#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	bool m_isTitle;
	bool m_isRetry;
};

