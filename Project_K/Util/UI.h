#pragma once
#include"Vec2.h"

class UI
{
public:
	UI(int Hp1, int Hp2);
	~UI() {};

	void Init() {}// 初期化
	void Update();// 更新処理
	void Draw();// 描画処理

	void HpUpdate();
	void HpDraw();

	void FontUpdate();
	void FontDraw();


	void GetHp1(int hp) { UI1.m_temp = hp; }// 1PのHP
	void GetHp2(int hp) { UI2.m_temp = hp; }// 2PのHP
	void AttackFlag(bool flag) { m_attackFlag = flag; }
private:

	Vec2 m_boxPos;

	struct  UIData
	{
		Vec2 m_pos = { 0,0 };// HPバーの位置
		int m_temp = 0;// HPをうけとる用の変数
		int m_life = 0;// 各プレイヤーのHP
		int m_lower = 0;// 仮で保存するHP用の変数
	};

	int m_countFrame;// 仮のHPを減らすタイマー

	bool m_attackFlag;
	UIData UI1;
	UIData UI2;
};
