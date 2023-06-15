#pragma once
class StageBase
{
public :
	StageBase();			// コンストラクタ
	virtual ~StageBase();	// デストラクタ

	void Init();	// 初期化
	void Update();	// 更新
	void Draw();	// 描画

	int GetStartX() const { return m_startX; }	// 始点座標Xの取得
	int GetStartY() const { return m_startY; }	// 始点座標Yの取得
	int GetEndX() const { return m_endX; }		// 終点座標Xの取得
	int GetEndY() const { return m_endY; }		// 終点座標Yの取得

protected :
	int m_handle;	// グラフィックハンドル
	int m_bgHandle;	// 背景用グラフィックハンドル

	int m_startX;	// 始点の座標X
	int m_startY;	// 始点の座標Y
	int m_endX;		// 終点の座標X
	int m_endY;		// 終点の座標Y
};

