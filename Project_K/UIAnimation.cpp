#include "UIAnimation.h"
#include "Util/DrawFunctions.h"
#include <DxLib.h>

//////////////////////
// UI画像作成クラス //
//////////////////////
UIAnimation::UIAnimation()
{
}

void UIAnimation::AddButton(int x, int y, int size, int animSpeed, ButtonNo buttonNo)
{
	m_pAnimUi.push_back(std::make_shared<ImageAnimation>(x,y,size, animSpeed,buttonNo));
}

void UIAnimation::Init()
{
	for (auto& ui : m_pAnimUi)
	{
		ui->Init();
	}
}

void UIAnimation::End()
{
	for (auto& ui : m_pAnimUi)
	{
		ui->End();
	}
}

void UIAnimation::Update()
{
	for (auto& ui : m_pAnimUi)
	{
		ui->Update();
	}
}

void UIAnimation::Draw()
{
	for (auto& ui : m_pAnimUi)
	{
		ui->Draw();
	}
}

/////////////////////////////////////////////
// UI画像を複製してアニメーションするクラス //
//////////////////////////////////////////////
ImageAnimation::ImageAnimation(int x, int y, int size, int animSpeed, ButtonNo buttonNo):
	m_hButton(-1),
	m_x(x),
	m_y(y),
	m_size(size),
	m_animSpeed(animSpeed),
	m_buttomNo(buttonNo),
	m_imgX(0),
	m_imgY(0),
	m_imgBottomX(0),
	m_imgBottomY(0),
	m_frameCount(0),
	m_isAnimXY(false)
{
	m_hButton = my::MyLoadGraph("Data/Image/UI/button.png");
	if (m_buttomNo == ButtonNo::Up)
	{
		m_hButton = my::MyLoadGraph("Data/Image/UI/AllButtons.png");
	}
}

ImageAnimation::~ImageAnimation()
{
	DeleteGraph(m_hButton);
}

void ImageAnimation::Init()
{
	// どのボタンのアニメーションにするか
	switch (m_buttomNo)
	{
	case ButtonNo::A:
		m_imgX = 16 * 2;
		m_imgY = 16 * 12;
		m_imgBottomX = 16;
		m_imgBottomY = 16;
		m_isAnimXY = true;
		break;
	case ButtonNo::B:
		m_imgX = 16 * 2;
		m_imgY = 16 * 14;
		m_imgBottomX = 16;
		m_imgBottomY = 16;
		m_isAnimXY = true;
		break;
	case ButtonNo::X:

		break;
	case ButtonNo::Y:

		break;
	case ButtonNo::Up:
		m_imgX = 16 * 6;
		m_imgY = 16 * 1;
		m_imgBottomX = 16;
		m_imgBottomY = 16;
		m_isAnimXY = false;
		break;
	case ButtonNo::Down:
		m_imgX = 16 * 6;
		m_imgY = 16 * 1;
		m_imgBottomX = 16;
		m_imgBottomY = 16;
		m_isAnimXY = false;
		break;
	default:
		break;
	}
}

void ImageAnimation::End()
{
}

void ImageAnimation::Update()
{
	m_frameCount++;

	if (m_isAnimXY)
	{
		if (m_frameCount > m_animSpeed)
		{
			m_frameCount = 0;
			if (m_imgX < 16 * 5)//画像が右に続いていたら右にずらす
			{
				m_imgX += 16;//X軸を右にずらす
			}
			else
			{
				m_imgX = 16 * 2;// 画像の描画させる位置を初期値に戻す
			}
		}
	}
	else
	{
		if (m_frameCount > m_animSpeed)
		{
			m_frameCount = 0;
			if (m_imgX == 16 * 10)
			{
				m_imgX = 16 * 8;
			}
			else
			{
				m_imgX = 16 * 10;
				
			}
		}
	}	
}

void ImageAnimation::Draw()
{
	my::MyDrawRectRotaGraph(m_x, m_y,// 位置
		m_imgX, m_imgY,// 画像の左上
		m_imgBottomX, m_imgBottomY,// 画像の右下
		m_size,// 大きさ
		DX_PI_F / 180.0f,// 角度
		m_hButton,// ハンドル
		true,// 透過
		false);// 反転
}
