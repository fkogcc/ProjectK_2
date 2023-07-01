#pragma once

namespace Game
{
#ifdef _DEBUG
	// �E�C���h�E���[�h�ݒ�
	constexpr bool kWindowModo = true;
#else
	constexpr bool kWindowModo = false;
#endif
	//�E�B���h�E��
	const char* const kTitleText = "Project_K";
	//�E�B���h�E�T�C�Y
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;
	//�J���[���[�h
	constexpr int kColorDepth = 32; //�R�Qor�P�U
};