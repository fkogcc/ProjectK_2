#include "SelectUI.h"
#include"game.h"
#include"DrawFunctions.h"
#include"DxLib.h"
#include"FontFunction.h"

namespace
{
	int kBottomStandard = Game::kScreenHeight - 150; // 下の基準線（選択プレイヤーの位置を下で合わせる）
	int kSelectFont = 0;// 上に表示するのに使用するフォント
	int kDinoFont = 0;// 恐竜くんが使用するフォント
	int kElfFont = 0;// エルフくんが使用するフォント
	int kKinFont = 0;// きんにくんが使用するフォント
	int kWitchFont = 0;// 魔女が使用するフォント
	const char* kSelectText = "character select";// 上に表示する文字
	const char* kDinoText = "だいなそー";// 表示する文字
	const char* kElfText = "Elf";// 表示する文字
	const char* kKinText = "きんにくん";// 表示する文字
	const char* kWitchText = "Witch";// 表示する文字

	int kColor1P = 0xffffff;// 1Pが使用する色
	int kColor2P = 0xffffff;// 2Pが使用する色
}

SelectUI::SelectUI() :
	m_frameHandle(0),
	m_dinoHandle(0),
	m_elfHandle(0),
	m_kinnikuHandle(0),
	m_witchHandle(0),
	m_frameCount1(0),
	m_indexWidth1(0),
	m_indexHight1(0),
	m_frameCount2(0),
	m_indexWidth2(0),
	m_indexHight2(0),
	m_cursor1(0),
	m_cursor2(0),
	m_cursorFlag1(false),
	m_cursorFlag2(false)
{

}

SelectUI::~SelectUI()
{
	// 画像のデリート処理
	my::MyDeleteGraph(m_frameHandle);
	my::MyDeleteGraph(m_dinoHandle);
	my::MyDeleteGraph(m_elfHandle);
	my::MyDeleteGraph(m_kinnikuHandle);
	my::MyDeleteGraph(m_witchHandle);

	// フォントのデリーtp
	DeleteFontToHandle(kSelectFont);
	DeleteFontToHandle(kDinoFont);
	DeleteFontToHandle(kElfFont);
	DeleteFontToHandle(kKinFont);
	DeleteFontToHandle(kWitchFont);
}

void SelectUI::Init()
{
	InitLoad();// 画像のロード
	InitFont();// フォントの初期化
	InitChar();// キャラクタの初期化処理
}

void SelectUI::Update()
{
	SelectCursor(m_cursor1, 1);// カーソルによってアップデート
	SelectCursor(m_cursor2, 2);// カーソルによってアップデート 
	UpdateAnimation();// アニメーション
}

void SelectUI::Draw()
{
	DrawChar();// キャラの描画
	DrawLetter();// 文字の初期化
}

void SelectUI::InitLoad()
{
	// 画像のロード処理
	m_frameHandle = my::MyLoadGraph("Data/Image/UI/frame.png");// フレーム
	m_dinoHandle = my::MyLoadGraph("Data/Image/Player/kyouryuu/Enemy.png");// 恐竜
	m_elfHandle = my::MyLoadGraph("Data/Image/Player/Elf/Elf.png");// エルフ
	m_kinnikuHandle = my::MyLoadGraph("Data/Image/Player/Kinnikurou/Idle.png");// きんにくん
	m_witchHandle = my::MyLoadGraph("Data/Image/Player/Witch/Witch.png");// 魔女
}

void SelectUI::InitFont()
{
	font::MyFontPath("Data/Font/Valentina-Regular.ttf");
	kSelectFont = CreateFontToHandle("Valentina", 100, -1, -1);// 上の表示する文字に使用するフォン

	font::MyFontPath("Data/Font/851letrogo_007.ttf");
	kDinoFont = CreateFontToHandle("851レトロゴ", 50, -1, -1);// 恐竜くん用フォント
	font::MyFontPath("Data/Font/Valentina-Regular.ttf");
	kElfFont = CreateFontToHandle("Valentina", 50, -1, -1);// エルフくん用フォント
	font::MyFontPath("Data/Font/kkm_analogtv.ttf");
	kKinFont = CreateFontToHandle("KKM-アナログテレビフォント", 50, -1, -1);// きんにくん用フォント
	font::MyFontPath("Data/Font/Utusi Star Normal.otf");
	kWitchFont = CreateFontToHandle("Utusi Star", 50, -1, -1);// 魔女用フォント
}

void SelectUI::InitChar()
{
	// P1の初期化
	m_player1.m_imgWidth = 0;
	m_player1.m_imgHight = 0;
	m_player1.m_imgSize = 0;
	m_player1.m_posY = 0;
	m_player1.m_maxWidth = 0;
	m_player1.m_maxHight = 0;
	m_player1.m_animFrame = 0;
	m_player1.m_text = kDinoText;
	m_player1.m_font = kDinoFont;
	m_temp = m_player1;// ここでまとめて初期化
	m_player2 = m_player1;// ついでに2Pもまとめて初期化

	// 恐竜くんの初期化
	m_dino.m_imgWidth = 640;
	m_dino.m_imgHight = 222;
	m_dino.m_imgSize = 2;
	float kyouryuuPos = kBottomStandard - (m_dino.m_imgHight * m_dino.m_imgSize / 2);
	m_dino.m_posY = kyouryuuPos;
	m_dino.m_maxWidth = 9;
	m_dino.m_maxHight = 2;
	m_dino.m_animFrame = 5;
	m_dino.m_text = kDinoText;
	m_dino.m_font = kDinoFont;


	// エルフくんの初期化
	m_elf.m_imgWidth = 288;
	m_elf.m_imgHight = 128;
	m_elf.m_imgSize = 7;
	float elfPos = kBottomStandard - (m_elf.m_imgHight * m_elf.m_imgSize / 2);
	m_elf.m_posY = elfPos;
	m_elf.m_maxWidth = 12;
	m_elf.m_maxHight = 0;
	m_elf.m_animFrame = 5;
	m_elf.m_text = kElfText;
	m_elf.m_font = kElfFont;

	// きんにくんの初期化
	m_kinnniku.m_imgWidth = 18;
	m_kinnniku.m_imgHight = 23;
	m_kinnniku.m_imgSize = 10;
	float kinPos = kBottomStandard - (m_kinnniku.m_imgHight * m_kinnniku.m_imgSize / 2);
	m_kinnniku.m_posY = kinPos;
	m_kinnniku.m_maxHight = 0;
	m_kinnniku.m_maxWidth = 2;
	m_kinnniku.m_animFrame = 60;
	m_kinnniku.m_text = kKinText;
	m_kinnniku.m_font = kKinFont;

	// 魔女の初期化
	m_witch.m_imgWidth = 48;
	m_witch.m_imgHight = 48;
	m_witch.m_imgSize = 6;
	float witchPos = kBottomStandard - (m_witch.m_imgHight * m_witch.m_imgSize / 2);
	m_witch.m_posY = witchPos;
	m_witch.m_maxWidth = 1;
	m_witch.m_maxHight = 8;
	m_witch.m_animFrame = 15;
	m_witch.m_text = kWitchText;
	m_witch.m_font = kWitchFont;

}

void SelectUI::UpdateAnimation()
{
	// 1Pのアニメーション
	m_frameCount1++;
	if (m_player1.m_animFrame <= m_frameCount1)
	{
		m_indexWidth1++;
		m_frameCount1 = 0;
	}
	if (m_player1.m_maxWidth <= m_indexWidth1)
	{
		m_indexHight1++;
		m_indexWidth1 = 0;
		m_frameCount1 = 0;
	}
	if (m_player1.m_maxHight <= m_indexHight1)
	{
		m_indexHight1 = 0;
	}
	// 2Pのアニメーション
	m_frameCount2++;
	if (m_player2.m_animFrame <= m_frameCount2)
	{
		m_indexWidth2++;
		m_frameCount2 = 0;
	}
	if (m_player2.m_maxWidth <= m_indexWidth2)
	{
		m_indexHight2++;
		m_indexWidth2 = 0;
		m_frameCount2 = 0;
	}
	if (m_player2.m_maxHight <= m_indexHight2)
	{
		m_indexHight2 = 0;
	}
}

void SelectUI::DrawChar()
{
	// フレーム
	for (int i = 1; i <= 4; i++)
	{
		int pos = 200;
		my::MyDrawRectRotaGraph(
			static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(48) + pos * i,//プレイヤーの位置
			0, 0,// 画像の右上
			48, 48,
			4,
			DX_PI_F * 2,
			m_frameHandle,
			true,
			false);
	}
	// アイコン(恐竜くん)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2 + 270), static_cast<int>(200 - 25),//プレイヤーの位置
		320, 0,// 画像の右上
		450, 180,
		1.5,
		DX_PI_F * 2,
		m_dinoHandle,
		true,
		false);
	// アイコン(Elfくん)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(200 + 10),//プレイヤーの位置
		0, 0,// 画像の右上
		288, 100,
		6,
		DX_PI_F * 2,
		m_elfHandle,
		true,
		false);
	// アイコン(きんにくん)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(600 + 50),//プレイヤーの位置
		0, 0,// 画像の右上
		18, 18,
		7,
		DX_PI_F * 2,
		m_kinnikuHandle,
		true,
		false);
	// アイコン(まじょ)
	my::MyDrawRectRotaGraph(
		static_cast<int>(Game::kScreenWidth / 2), static_cast<int>(840),//プレイヤーの位置
		0, 0,// 画像の右上
		48, 30,
		5,
		DX_PI_F * 2,
		m_witchHandle,
		true,
		false);


	// 1Pが選択してるキャラ
	my::MyDrawRectRotaGraph(
		400, static_cast<int>(m_player1.m_posY),//プレイヤーの位置
		m_player1.m_imgWidth * m_indexWidth1, m_player1.m_imgHight * m_indexHight1,// 画像の右上
		m_player1.m_imgWidth, m_player1.m_imgHight,// 画像の切り取り
		m_player1.m_imgSize,// 画像の拡大率
		DX_PI_F * 2,// 回転
		m_player1.m_handle,// 画像
		true,// 反転
		false);// 透過

	// 2Pが選択してるキャラ
	my::MyDrawRectRotaGraph(
		Game::kScreenWidth - 400, static_cast<int>(m_player2.m_posY),//プレイヤーの位置
		m_player2.m_imgWidth * m_indexWidth2, m_player2.m_imgHight * m_indexHight2,// 画像の右上
		m_player2.m_imgWidth, m_player2.m_imgHight,// 画像の切り取り
		m_player2.m_imgSize,// 画像の拡大率
		DX_PI_F * 2,// 回転
		m_player2.m_handle,// 画像
		true,// 反転
		true);// 透過
}

void SelectUI::DrawLetter()
{
	// キャラクターセレクトの表示
	DrawStringToHandle((Game::kScreenWidth -
		GetDrawStringWidthToHandle(kSelectText, 16, kSelectFont)) / 2,
		100 - 35, kSelectText, 0x800000, kSelectFont);

	// 1Pの名前表示
	DrawStringToHandle(400,
		300, m_player1.m_text, kColor1P, m_player1.m_font);
	// 2Pの名前表示
	DrawStringToHandle(Game::kScreenWidth - 400,
		300, m_player2.m_text, kColor2P, m_player2.m_font);
}

void SelectUI::SelectCursor(int cursor, int selectNum)
{
	// カーソルがいる位置で処理を変更する
	if (cursor == 0)
	{
		// 恐竜くん
		m_temp.m_imgWidth = m_dino.m_imgWidth;
		m_temp.m_imgHight = m_dino.m_imgHight;
		m_temp.m_imgSize = m_dino.m_imgSize;
		m_temp.m_posY = m_dino.m_posY;
		m_temp.m_maxWidth = m_dino.m_maxWidth;
		m_temp.m_maxHight = m_dino.m_maxHight;
		m_temp.m_animFrame = m_dino.m_animFrame;
		m_temp.m_handle = m_dinoHandle;
		m_temp.m_text = m_dino.m_text;
		m_temp.m_font = m_dino.m_font;
	}
	if (cursor == 1)
	{
		// エルフくん
		m_temp.m_imgWidth = m_elf.m_imgWidth;
		m_temp.m_imgHight = m_elf.m_imgHight;
		m_temp.m_imgSize = m_elf.m_imgSize;
		m_temp.m_posY = m_elf.m_posY;
		m_temp.m_maxWidth = m_elf.m_maxWidth;
		m_temp.m_maxHight = m_elf.m_maxHight;
		m_temp.m_animFrame = m_elf.m_animFrame;
		m_temp.m_handle = m_elfHandle;
		m_temp.m_text = m_elf.m_text;
		m_temp.m_font = m_elf.m_font;
	}
	if (cursor == 2)
	{
		// きんにくん
		m_temp.m_imgWidth = m_kinnniku.m_imgWidth;
		m_temp.m_imgHight = m_kinnniku.m_imgHight;
		m_temp.m_imgSize = m_kinnniku.m_imgSize;
		m_temp.m_posY = m_kinnniku.m_posY;
		m_temp.m_maxWidth = m_kinnniku.m_maxWidth;
		m_temp.m_maxHight = m_kinnniku.m_maxHight;
		m_temp.m_animFrame = m_kinnniku.m_animFrame;
		m_temp.m_handle = m_kinnikuHandle;
		m_temp.m_text = m_kinnniku.m_text;
		m_temp.m_font = m_kinnniku.m_font;
	}
	if (cursor == 3)
	{
		// 魔女
		m_temp.m_imgWidth = m_witch.m_imgWidth;
		m_temp.m_imgHight = m_witch.m_imgHight;
		m_temp.m_imgSize = m_witch.m_imgSize;
		m_temp.m_posY = m_witch.m_posY;
		m_temp.m_maxWidth = m_witch.m_maxWidth;
		m_temp.m_maxHight = m_witch.m_maxHight;
		m_temp.m_animFrame = m_witch.m_animFrame;
		m_temp.m_handle = m_witchHandle;
		m_temp.m_text = m_witch.m_text;
		m_temp.m_font = m_witch.m_font;
	}
	// 渡した数によってPADがどっちかを分岐させる
	if (selectNum == 1)
	{
		m_player1 = m_temp;
	}
	else
	{
		m_player2 = m_temp;
	}
	// 決定されていたら各プレイヤーの色にする
	// そうではなかったらデフォルトで白を渡す
	if (m_cursorFlag1)// 1P
	{
		kColor1P = 0xff0000;
	}
	else
	{
		kColor1P = 0xffffff;
	}
	if (m_cursorFlag2)// 2P
	{
		kColor2P = 0x0000ff;
	}
	else
	{
		kColor2P = 0xffffff;
	}
}