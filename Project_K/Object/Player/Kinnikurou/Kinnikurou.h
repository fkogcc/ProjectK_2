#pragma once

#include "../Base/PlayerBase.h"

class KinnikuIdle;
class KinnikurouJab;
class KinnikuMuscle;
class KinnikuUpper;
class KinnikuMizo;
class KinnikuRun;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// 初期化
	void End   ();// 終了処理
	void Update();// 更新
	void Draw  ();// 描画

	void ImgposInit();

private:

	KinnikuIdle* m_pIdle;
	KinnikurouJab* m_pJab;
	KinnikuMuscle* m_pMuscle;
	KinnikuUpper* m_pUpper;
	KinnikuMizo* m_pMizo;
	KinnikuRun* m_pRun;

	bool m_pushBottom;

	// ハンドル
	int m_charHandle;// キャラクター全体
	int m_idleHandle;// アイドル状態
	int m_jabHandle;// ジャブ攻撃状態
	int m_muscleHandle;// マッスル攻撃状態
	int m_UpperHandle;// アッパー攻撃状態
	int m_MizoHandle;// みぞおち攻撃状態
	int m_RunHandle;//移動状態

	// 画像の座標
	int m_imgPosX;// X
	int m_imgPosY;// Y

	// 画像の一片の長さ
	int m_imgWidth;// X
	int m_imgHeight;// Y

	// モーション終わりのカウント
	int m_motionCount;

	// 初期化回数
	int m_initCount;

	// キャラの向き
	bool m_charDirection;

	// キャラが移動状態かどうか
	bool m_charRun;
};

