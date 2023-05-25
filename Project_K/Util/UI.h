#pragma once
#include"Vec2.h"

class UI
{
public:
	UI();
	~UI() {};

	void Init() {}// 初期化
	void Update();// 更新処理
	void Draw();// 描画処理

	void GetHp1(int hp) { UI1.m_life = hp; }// 1PのHP
	void GetHp2(int hp) { UI2.m_life = hp; }// 2PのHP
private:

	Vec2 m_boxPos;

	struct  UIData
	{
		Vec2 m_pos = { 0,0 };// HPバーの位置
		int m_life = 0;// 各プレイヤーのHP
		int m_temp = 0;// 仮で保存するHP用の変数
	};

	int m_countFrame;// 仮のHPを減らすタイマー


	UIData UI1;
	UIData UI2;
};
