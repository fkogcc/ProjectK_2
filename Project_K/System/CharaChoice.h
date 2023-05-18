#pragma once
#include<array>

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

private:
	void updateChara1();
	void updateChara2();

	int m_choiceNum1;
	int m_choiceNum2;

	std::array<bool, 4> m_chackChara1;
	std::array<bool, 4> m_chackChara2;
};