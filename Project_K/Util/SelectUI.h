#pragma once
#include"Vec2.h"

class SelectUI
{
private:
	// 構造体
	struct  AnimeData// 各キャラクタが持つ情報
	{
		float m_posY = 0;// 位置
		int m_imgWidth = 0;// 切り取る幅
		int m_imgHight = 0;// 切り取る高さ
		float m_imgSize = 0;// 画像の大きさ（拡大率）
		int m_handle = -1;// 画像

		int m_maxWidth = 0;// アニメーションの横の最大値
		int m_maxHight = 0;// アニメーションの縦の最大値
		int m_animFrame = 0;// アニメーションの速度（フレーム数）
		const char* m_text = 0;// テキスト（キャラ名）
		int m_font = 0;// 使用するフォント
	};
public:

	SelectUI();// コンストラクタ
	virtual ~SelectUI();// デストラクタ

	void Init();// 初期化
	void Update();// 更新処理
	void Draw();// 描画処理

	void InitLoad();// ロード処理
	void InitFont();// ロード処理
	void InitChar();// キャラクタの初期化処理
	void SetCursor(int cursor1, int cursor2) { m_cursor1 = cursor1; m_cursor2 = cursor2; }// カーソルを受け取る関数
	void SetCursorFlag(bool cursorFlag1, bool cursorFlag2) { m_cursorFlag1 = cursorFlag1; m_cursorFlag2 = cursorFlag2; }// カーソルのフラグを受け取る
	void UpdateAnimation();// アニメーション処理
	void DrawChar();// キャラクタの描画処理
	void DrawLetter();//テキストの描画処理
	void SelectCursor(int cursor, int selectNum);//選ばれているカーソルによって処理を変える

private:
	//画像を入れる変数
	int m_frameHandle;// 枠
	int m_dinoHandle;// 恐竜くん
	int m_elfHandle;// エルフくん
	int m_kinnikuHandle;// 筋肉くん
	int m_witchHandle;// 魔女

	AnimeData m_temp;// 一時的に保存する用の変数
	AnimeData m_player1;// 1P
	AnimeData m_player2;// 2P
	AnimeData m_dino;// 恐竜くん
	AnimeData m_elf;// エルフくん
	AnimeData m_kinnniku;// 筋肉くん
	AnimeData m_witch;// 魔女

	int m_frameCount1;// 1Pのアニメーション用フレーム
	int m_indexWidth1;// 1Pのアニメーション用縦
	int m_indexHight1;// 1Pのアニメーション用横
	int m_frameCount2;// 2Pのアニメーション用フレーム
	int m_indexWidth2;// 2Pのアニメーション用縦
	int m_indexHight2;// 2Pのアニメーション用横

	int m_cursor1;// カーソルの位置保存1P用
	int m_cursor2;// カーソルの位置保存2P用
	bool m_cursorFlag1;// カーソルのフラグ保存1P用
	bool m_cursorFlag2;// カーソルのフラグ保存2P用
};