#pragma once
#include "SceneBase.h"
#include "../Util/common.h"
#include "../Util/Vec2.h"

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
	Vec2 m_pos;

	//**** UI用グラフィックハンドル ****//
	int m_stageHandle;	// 
	int m_bgHandle;		// 背景
	int m_handle;
	int m_font;			// フォントハンドル

	// マップ判別用の番号変数
	int m_mapNum;
};

