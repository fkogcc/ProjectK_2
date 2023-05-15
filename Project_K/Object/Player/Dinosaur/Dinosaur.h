#pragma once
#include "../Base/PlayerBase.h"
#include<array>

class ShotBase;
class DinosaurStateManager;

class Dinosaur : public PlayerBase
{
public:
	Dinosaur();
	~Dinosaur();

	void Init();// 初期化
	void End();// 終了処理
	void Update();// 更新
	void Draw()override;// 描画

	void GetAttackSize();

	ShotBase* GetShot(int i);
private:
	int m_Handle;
	DinosaurStateManager* m_StateManager;

	bool m_LookRight;	// 右を見てるとき
};

