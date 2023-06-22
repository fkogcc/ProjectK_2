#pragma once
#include <vector>
#include <memory>
#include "ButtonNo.h"

class ImageAnimation;
/// <summary>
/// UI画像作成クラス
/// </summary>
class UIAnimation
{
public:
	UIAnimation();
	virtual ~UIAnimation() {};

	/// <summary>
	/// ボタン画像のアニメーション
	/// </summary>
	/// <param name="x">位置</param>
	/// <param name="y">位置</param>
	/// <param name="size">大きさ</param>
	/// <param name="animSpeedint">アニメーションの再生スピード</param>
	/// <param name="buttonNo">どのボタンをアニメーションさせるか</param>
	void AddButton(int x,int y,int size,int animSpeedint , ButtonNo buttonNo);
	void Init();
	void End();
	void Update();
	void Draw();
private:
	std::vector<std::shared_ptr<ImageAnimation>>m_pAnimUi;
};

/// <summary>
/// UI画像を複製してアニメーションするクラス
/// </summary>
class ImageAnimation
{
public:
	ImageAnimation(int x, int y, int size, int animSpeed, ButtonNo buttonNo);
	virtual ~ImageAnimation(){};

	void Init();
	void End();
	void Update();
	void Draw();

private:
	int m_hButton;// ボタン画像ハンドル
	int m_x;// 位置
	int m_y;// 位置
	int m_size;// 大きさ
	int m_animSpeed;// アニメーションスピード
	ButtonNo m_buttomNo;// どのボタンを描画させるか
	int m_imgX;
	int m_imgY;
	int m_frameCount;
};
