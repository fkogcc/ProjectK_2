#pragma once

#include "../Base/PlayerBase.h"

class KinnnikurouIdle;
class KinnikurouJab;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// 初期化
	void End   ();// 終了処理
	void Update();// 更新
	void Draw  ();// 描画
private:

	KinnnikurouIdle* m_pIdle;

	bool m_pushBottom;

	// ハンドル
	int m_charHandle;// キャラクター全体
	int m_idleHandle;// アイドル状態
	int m_jabHandle;// ジャブ攻撃状態

	// 描画座標
	int m_drawPosX;// X
	int m_drawPosY;// Y

	// 画像の座標
	int m_imgPosX;// X
	int m_imgPosY;// Y

};

