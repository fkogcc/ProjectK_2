#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include "../Util/Vec2.h"

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
	// 
	int m_hLogo;

	Vec2 m_pos;
	Vec2 m_logoPos;
};

