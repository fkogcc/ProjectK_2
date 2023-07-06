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
	m_handle(-1),
	m_x(x),
	m_y(y),
	m_size(size),
	m_animSpeed(animSpeed),
	m_buttomNo(buttonNo),
	m_imgX(0),
	m_imgY(0),
	m_frameCount(0),
	m_isNoMove(false),
	m_imgBottomX(0),
	m_imgBottomY(0),
	m_isAnimXY(false)
{
	// �����͊֐��� //
	if (m_buttomNo == ButtonNo::X ||
		m_buttomNo == ButtonNo::Y || 
		m_buttomNo == ButtonNo::A || 
		m_buttomNo == ButtonNo::B )
	{
		m_handle = my::MyLoadGraph("Data/Image/UI/button.png");
	}
	else if (m_buttomNo == ButtonNo::Up)
	{
		m_handle = my::MyLoadGraph("Data/Image/UI/AllButtons.png");
	}
	else if (m_buttomNo == ButtonNo::Dinosaur)
	{
		int tempHandle = my::MyLoadGraph("Data/Image/Player/kyouryuu/Enemy.png");
		m_handle = DerivationGraph(320, 0, 450, 180, tempHandle);
		m_isNoMove = true;
	}
	else if (m_buttomNo == ButtonNo::Elf)
	{
		int tempHandle = my::MyLoadGraph("Data/Image/Player/Elf/Elf.png");
		m_handle = DerivationGraph(0, 0, 280, 100, tempHandle);
		m_isNoMove = true;
		/*m_handle = ImageCut(0, 0, 280, 100, "Data/Image/Player/Elf/Elf.png");*/
	}
	else if (m_buttomNo == ButtonNo::Kinnikurou)
	{
		int tempHandle = my::MyLoadGraph("Data/Image/Player/Kinnikurou/Idle.png");
		m_handle = DerivationGraph(0, 0, 18, 18, tempHandle);
		m_isNoMove = true;
	}
	else if (m_buttomNo == ButtonNo::Witch)
	{
		int tempHandle = my::MyLoadGraph("Data/Image/Player/Witch/Witch.png");
		m_handle = DerivationGraph(0, 0, 48, 30, tempHandle);
		m_isNoMove = true;
	}
}

ImageAnimation::~ImageAnimation()
{
	my::MyDeleteGraph(m_handle);
	DeleteGraph(m_hButton);
}

void ImageAnimation::Init()
{
	// �ǂ̃{�^���̃A�j���[�V�����ɂ��邩
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
	case ButtonNo::Dinosaur:
		m_imgX = 0;
		m_imgY = 0;
		m_imgBottomX = 130;//450;
		m_imgBottomY = 180;
		break;
	case ButtonNo::Elf:
		m_imgX = 0;
		m_imgY = 0;
		m_imgBottomX = 280;
		m_imgBottomY = 120;
		break;
	case ButtonNo::Kinnikurou:
		m_imgX = 0;
		m_imgY = 0;
		m_imgBottomX = 18;
		m_imgBottomY = 18;
		break;
	case ButtonNo::Witch:
		m_imgX = 0;
		m_imgY = 0;
		m_imgBottomX = 48;
		m_imgBottomY = 30;
		break;
	default:
		// �������Ȃ��B
		break;
	}
}

void ImageAnimation::End()
{
}

void ImageAnimation::Update()
{
	m_frameCount++;
	if (!m_isNoMove)
	{
		if (m_isAnimXY)
		{
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
}

void ImageAnimation::Draw()
{
	my::MyDrawRectRotaGraph(m_x, m_y,// �ʒu
		m_imgX, m_imgY,// �摜�̍���
		m_imgBottomX, m_imgBottomY,// �摜�̉E��
		static_cast<int>(m_size),// �傫��
		DX_PI_F / 180.0f,// �p�x
		m_handle,// �n���h��
		true,// ����
		false);// ���]
}

int ImageAnimation::ImageCut(int cutLeftUpX, int cutLeftUpY, int cutRightDownX, int cutRightDownY, const char* handle)
{

	return 0;
}
