#pragma once

#include "../Base/PlayerBase.h"

class KinnikuIdle;
class KinnikurouJab;
class KinnikuMuscle;
class KinnikuUpper;
class KinnikuMizo;
class KinnikuRun;
class KinnikuJump;
class KinnikuDead;

class Kinnikurou : public PlayerBase
{
public:
	Kinnikurou();
	virtual ~Kinnikurou();

	void Init  ();// 初期化
	void End   ();// 終了処理
	void Update();// 更新
	void Draw()override;// 描画

	void ImgposInit();


	void DrawBoxAttackCol();

	// 攻撃の当たり判定
	void AttackCol();

	// 攻撃していないとき
	void NoAttack();

private:

	KinnikuIdle* m_pIdle;		// アイドル状態
	KinnikurouJab* m_pJab;		// ジャブ攻撃
	KinnikuMuscle* m_pMuscle;	// 胸筋衝撃波
	KinnikuUpper* m_pUpper;		// アッパー状態
	KinnikuMizo* m_pMizo;		// みぞおち状態
	KinnikuRun* m_pRun;			// 走っている状態
	KinnikuJump* m_pJump;		// ジャンプ状態
	KinnikuDead* m_pDead;		// やられた状態

	// ハンドル
	int m_charHandle;	// キャラクター全体
	int m_idleHandle;	// アイドル状態
	int m_jabHandle;	// ジャブ攻撃状態
	int m_muscleHandle;	// 胸筋衝撃波攻撃状態
	int m_UpperHandle;	// アッパー攻撃状態
	int m_MizoHandle;	// みぞおち攻撃状態
	int m_RunHandle;	// 移動状態
	int m_JumpHandle;	// ジャンプ状態
	int m_FallHandle;	// 落下状態
	int m_DeadHandle;	// 死亡状態

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

	// ジャンプ加速度
	float m_jumpAcc;

	// キャラの向き
	bool m_charDirection;

	// キャラが移動状態かどうか
	bool m_charRun;

	// キャラがジャンプ中かどうか
	float m_isJump;
};

