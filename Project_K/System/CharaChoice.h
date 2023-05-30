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

	int GetChackChara1() { return m_charaNumber1; }
	int GetChackChara2() { return m_charaNumber2; }

	bool GetDecision1() { return m_Decision1; }
	bool GetDecision2() { return m_Decision2; }

private:
	void updateChara1();
	void updateChara2();

	int m_charaNumber1;
	int m_charaNumber2;

	bool m_Decision1;
	bool m_Decision2;
};