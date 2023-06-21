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

	// 選択された番号によってマップを選ぶ
	virtual void ChooseNum();

private:
	// マップ判別用の番号変数
	int m_mapNum;
};

