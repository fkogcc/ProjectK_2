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
	bool m_isTitle;// タイトルへ
	bool m_isRetry;// リトライ

	bool m_isNone = false;// 条件の中身がない状態
};

