#include "UIAnimation.h"
#include "Util/DrawFunctions.h"
#include <DxLib.h>

//////////////////////
// UI�摜�쐬�N���X //
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
// UI�摜�𕡐����ăA�j���[�V��������N���X //
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
	m_frameCount(0)
{
	m_hButton = my::MyLoadGraph("Data/Image/UI/button.png");
}

void ImageAnimation::Init()
{
	switch (m_buttomNo)
	{
	case ButtonNo::A:
		m_imgX = 16 * 2;
		m_imgY = 16 * 12;
		break;
	case ButtonNo::B:
		m_imgX = 16 * 2;
		m_imgY = 16 * 14;
		break;
	case ButtonNo::X:

		break;
	case ButtonNo::Y:

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
	if (m_frameCount > m_animSpeed)
	{
		m_frameCount = 0;
		if (m_imgX < 16 * 5)//�摜���E�ɑ����Ă�����E�ɂ��炷
		{
			m_imgX += 16;//X�����E�ɂ��炷
		}
		else
		{
			m_imgX = 16 * 2;// �摜�̕`�悳����ʒu�������l�ɖ߂�
		}
	}
}

void ImageAnimation::Draw()
{
	my::MyDrawRectRotaGraph(m_x, m_y,// �ʒu
		m_imgX, m_imgY,// �摜�̍���
		16, 16,// �摜�̉E��
		m_size,// �傫��
		DX_PI_F / 108.0f,// �p�x
		m_hButton,// �n���h��
		true,// ����
		false);// ���]
}
