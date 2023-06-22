#pragma once
#include <vector>
#include <memory>
#include "ButtonNo.h"

class ImageAnimation;
/// <summary>
/// UI�摜�쐬�N���X
/// </summary>
class UIAnimation
{
public:
	UIAnimation();
	virtual ~UIAnimation() {};

	/// <summary>
	/// �{�^���摜�̃A�j���[�V����
	/// </summary>
	/// <param name="x">�ʒu</param>
	/// <param name="y">�ʒu</param>
	/// <param name="size">�傫��</param>
	/// <param name="animSpeedint">�A�j���[�V�����̍Đ��X�s�[�h</param>
	/// <param name="buttonNo">�ǂ̃{�^�����A�j���[�V���������邩</param>
	void AddButton(int x,int y,int size,int animSpeedint , ButtonNo buttonNo);
	void Init();
	void End();
	void Update();
	void Draw();
private:
	std::vector<std::shared_ptr<ImageAnimation>>m_pAnimUi;
};

/// <summary>
/// UI�摜�𕡐����ăA�j���[�V��������N���X
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
	int m_hButton;// �{�^���摜�n���h��
	int m_x;// �ʒu
	int m_y;// �ʒu
	int m_size;// �傫��
	int m_animSpeed;// �A�j���[�V�����X�s�[�h
	ButtonNo m_buttomNo;// �ǂ̃{�^����`�悳���邩
	int m_imgX;
	int m_imgY;
	int m_frameCount;
};
