#include "SceneMain.h"
#include "../Object/Player/Elf/Elf.h"
#include "../Util/DrawFunctions.h"
#include "../Object/Player/Elf/ElfIdol.h"
#include "../Object/Player/Elf/ElfAttackArrowPunch.h"
#include "../Object/Player/Elf/ElfAttackArrowShot.h"
#include "../Object/Player/Elf/ElfAttackArrowChargeShot.h"
#include "../condition.h"
#include <assert.h>

#include <iostream>

namespace// ここは仮のネームスペースです 候補：キャラ選択画面
{
	const char* const kPlayerImage = "Data/Image/Player/Elf/Elf.png";
}
SceneMain::SceneMain(bool player1, bool player2, bool player3, bool player4) :
	m_pos             (0.0f,0.0f),// プレイヤー位置
	m_pElf            (nullptr),  // エルフ用ポインタ類
	m_pElfIdol        (nullptr),
	m_pElfAttackNormal(nullptr),
	m_pElfAttackShot  (nullptr),
	m_pElfAttackChargeShot(nullptr)
{
	m_isPlayerDrawTest[0] = player1;
	m_isPlayerDrawTest[1] = player2;
	m_isPlayerDrawTest[2] = player3;
	m_isPlayerDrawTest[3] = player4;

	m_pElf                 = new Elf;// エルフ用ポインタ類
	m_pElfIdol             = new ElfIdol;
	m_pElfAttackNormal     = new ElfAttackArrowPunch;
	m_pElfAttackShot       = new ElfAttackArrowShot;
	m_pElfAttackChargeShot = new ElfAttackArrowChargeShot;

	for (int i = 0; i < 4; i++)
	{
		m_vPos.push_back(Vec2(0.0f, 0.0f));
		m_vImageX.push_back(0);
		m_vImageY.push_back(0);
		m_vImageSizeX.push_back(288);
		m_vImageSizeY.push_back(128);
		m_vHPlayer.push_back(-1);
	}
}

SceneMain::~SceneMain()
{
	delete m_pElf;// エルフポインタ解放
	delete m_pElfIdol;
	delete m_pElfAttackNormal;
	delete m_pElfAttackShot;
	delete m_pElfAttackChargeShot;
}

void SceneMain::Init()
{
//	m_hPlayer = my::MyLoadGraph(kPlayerImage);// メモリに画像データ読み込み
	m_vHPlayer[0] = my::MyLoadGraph(kPlayerImage);// メモリに画像データ読み込み

	//writing_file.open(filename, std::ios::ate);//appファイル末尾から入力開始
	//writing_file.close();// ファイルを閉じる
}

void SceneMain::End()
{
	my::MyDeleteGraph(m_hPlayer);//画像データメモリ解放
}

void SceneMain::ElfMoveIdol()// エルフ待機モーション
{
	m_pElfIdol->Update();// エルフのアイドル状態
	if (m_pElf->SetMove() == static_cast<int>(moveType::Idol))// 何もしていない場合はアイドル状態
	{
		//m_imageX = m_pElfIdol->SetPosImageX();// アイドル状態用画像モーション位置
		//m_imageY = m_pElfIdol->SetPosImageY();
		m_vImageX[0] = m_pElfIdol->SetPosImageX();// アイドル状態用画像モーション位置
		m_vImageY[0] = m_pElfIdol->SetPosImageY();
	}
}

void SceneMain::ElfMoveAttack()// エルフ基本攻撃モーション
{
	m_pElfAttackNormal->Update();// エルフの攻撃モーション
	if (m_pElf->SetMove() == static_cast<int>(moveType::Attack1))// プレイヤーがPad1を押したら攻撃
	{
		m_pElfAttackNormal->SetMoveTime(true);// 攻撃を有効化
	}
	if (m_pElfAttackNormal->IsSetMove())// 攻撃アニメーションを再生
	{
	//	m_imageX = m_pElfAttackNormal->SetPosImageX();// 攻撃用画像モーション位置
	//	m_imageY = m_pElfAttackNormal->SetPosImageY();
		m_vImageX[0] = m_pElfAttackNormal->SetPosImageX();// 攻撃用画像モーション位置
		m_vImageY[0] = m_pElfAttackNormal->SetPosImageY();

		if (!m_pElfAttackNormal->IsSetMove())// アニメーションが最後まで再生されたら
		{
			m_pElfAttackNormal->SetMoveTime(false);// アニメーション停止
		}
	}
}

void SceneMain::ElfMoveAttackShot()
{
	m_pElfAttackShot->Update();// エルフの攻撃モーション
	if (m_pElf->SetMove() == static_cast<int>(moveType::Attack2))// プレイヤーがPad1を押したら攻撃
	{
		m_pElfAttackShot->SetMoveTime(true);// 攻撃を有効化
	}
	if (m_pElfAttackShot->IsSetMove())// 攻撃アニメーションを再生
	{
	//  m_imageX = m_pElfAttackShot->SetPosImageX();// 攻撃用画像モーション位置
	//	m_imageY = m_pElfAttackShot->SetPosImageY();
		m_vImageX[0] = m_pElfAttackShot->SetPosImageX();// 攻撃用画像モーション位置
		m_vImageY[0] = m_pElfAttackShot->SetPosImageY();

		if (!m_pElfAttackShot->IsSetMove())// アニメーションが最後まで再生されたら
		{
			m_pElfAttackShot->SetMoveTime(false);// アニメーション停止
		}
	}
}

void SceneMain::ElfMoveAttackChargeShot()
{
	m_pElfAttackChargeShot->Update();// エルフの攻撃モーション
	if (m_pElf->SetMove() == static_cast<int>(moveType::Attack3))// プレイヤーがPad1を押したら攻撃
	{
		m_pElfAttackChargeShot->SetMoveTime(true);// 攻撃を有効化
	}
	if (m_pElfAttackChargeShot->IsSetMove())// 攻撃アニメーションを再生
	{
	//	m_imageX = m_pElfAttackChargeShot->SetPosImageX();// 攻撃用画像モーション位置
	//	m_imageY = m_pElfAttackChargeShot->SetPosImageY();
		m_vImageX[0] = m_pElfAttackChargeShot->SetPosImageX();// 攻撃用画像モーション位置
		m_vImageY[0] = m_pElfAttackChargeShot->SetPosImageY();

		if (!m_pElfAttackChargeShot->IsSetMove())// アニメーションが最後まで再生されたら
		{
			m_pElfAttackChargeShot->SetMoveTime(false);// アニメーション停止
		}
	}
}

void SceneMain::ElfData()// エルフ位置などの代入
{
	//m_pos.x = m_pElf->SetPos().x;// エルフの位置
	//m_pos.y = m_pElf->SetPos().y;

	m_vPos[0].x = m_pElf->SetPos().x;// エルフの位置
	m_vPos[0].y = m_pElf->SetPos().y;

	m_left   = m_pElf->SetPosLeft  ();
	m_top    = m_pElf->SetPosTop   ();
	m_right  = m_pElf->SetPosRight ();
	m_bottom = m_pElf->SetPosBottom();
}

SceneBase* SceneMain::Update()
{
	if (m_isPlayerDrawTest)// エルフが選択されたかどうか
	{
		m_pElf->Update();// エルフの行動命令
		ElfMoveIdol	           ();// エルフ待機モーション
		ElfMoveAttack	       ();// エルフ基本攻撃モーション
		ElfMoveAttackShot      ();// エルフ弓矢で攻撃モーション
		ElfMoveAttackChargeShot();// エルフチャージショット攻撃モーション
		ElfData                ();// エルフ位置,方向,攻撃力,のデータ
	}



	return this;
}

void SceneMain::Draw()
{
	if (m_isPlayerDrawTest)// エルフが選択されたかどうか
	{
		// プレイヤーアニメーション描画
		//my::MyDrawRectRotaGraph(m_pos.x, m_pos.y,
		//	m_imageX, m_imageY, 288, 128,
		//	1.5 * 3, DX_PI * 2, m_hPlayer, true, false);
		// エルフの画像１キャラ
		// 横288
		// 縦136
	}

	for (int i = 0; i < 4; i++)
	{
		my::MyDrawRectRotaGraph(m_vPos[i].x, m_vPos[i].y,
			m_vImageX[i], m_vImageY[i], m_vImageSizeX[i], m_vImageSizeY[i],
			1.5 * 3, DX_PI * 2, m_vHPlayer[i], true, false);
	}


	DrawBox(m_left, m_top, m_right,m_bottom,0xff0000,false);// 当たり判定確認用
}


void SceneMain::test(std::string writing_text)// 引数は入力文字
{
	writing_file.open(filename, std::ios::app);// ファイルのどこに書き込むか
	assert(writing_file);// ファイル正常に動いているか確認
	writing_file << writing_text << std::endl;// 書き込み
	writing_file.close();// ファイルを閉じる
}
