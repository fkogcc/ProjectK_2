#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

class Elf;
class ElfIdol;
class ElfAttackArrowPunch;
class ElfAttackArrowShot;
class ElfAttackArrowChargeShot;

class Kinnikurou;

class Stage;

class SceneMain : public SceneBase
{
public:
	SceneMain(bool player1, bool player2, bool player3, bool player4);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	void test(std::string writing_text);// 引数は入力文字

private:

	void ElfMoveIdol();// エルフ待機モーション
	void ElfMoveAttack();// エルフ基本攻撃モーション
	void ElfMoveAttackShot();// エルフ弓矢で攻撃モーション
	void ElfMoveAttackChargeShot();// エルフチャージショット攻撃モーション
	void ElfData();// エルフ位置,方向,攻撃力,のデータ

	int m_hPlayer = -1;// プレイヤー画像データ
	std::vector<int>m_vHPlayer;

	int m_playerNum;

	int m_imageX = 0, m_imageY = 0;// プレイヤー画像位置
	std::vector<int>m_vImageX, m_vImageY;
	std::vector<int>m_vImageSizeX, m_vImageSizeY;

	int m_left = 0, m_top = 0, m_right = 0, m_bottom = 0;

	Vec2 m_pos = { 0.0f,0.0f };//プレイヤー位置

	std::vector<Vec2> m_vPos = { {0.0f,0.0f},{0.0f,0.0f} };// プレイヤー位置を宣言

	Elf* m_pElf;// エルフポインタ類
	ElfIdol* m_pElfIdol;
	ElfAttackArrowPunch* m_pElfAttackNormal;
	ElfAttackArrowShot* m_pElfAttackShot;
	ElfAttackArrowChargeShot* m_pElfAttackChargeShot;

	Kinnikurou* m_pKinnikurou;

	std::shared_ptr<Stage> m_pStage;// ステージのポインタ

	bool m_isPlayerDrawTest[4];

	std::ofstream writing_file;
	std::string filename = "Test.csv";

	std::string str;


};


	