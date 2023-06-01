#pragma once
#include<DxLib.h>

namespace
{
	constexpr int kCharaNum = 4; //キャラクターの数
}

class CharaChoice
{
public:
	CharaChoice();
	virtual ~CharaChoice();

	void Init();
	void Update();
	void Draw();

	//キャラナンバーを返す
	int GetChackChara1() { return m_charaNumber1; }
	int GetChackChara2() { return m_charaNumber2; }

	//キャラクター決定情報を返す.
	bool GetDecision1() { return m_Decision1; }
	bool GetDecision2() { return m_Decision2; }

private:
	//キャラナンバーのアップデート
	void updateChara1();
	void updateChara2();

	// キャラナンバー(0:恐竜 1:きんに君2:エルフ3:魔女)
	int m_charaNumber1;
	int m_charaNumber2;

	
	bool m_Decision1;// キャラクター1が決定されたか
	bool m_Decision2;// キャラクター2が決定されたか
};