#pragma once

namespace Game
{
	//�E�B���h�E���[�h
#ifdef _DEBUG
	constexpr bool kWindowMode = true;
#else
	constexpr bool kWindowMode = false;
#endif
	//�E�B���h�E��
	const char* const kTitleText = "Project_K";
	//�E�B���h�E�T�C�Y
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;
	//�J���[���[�h
	constexpr int kColorDepth = 32; //�R�Qor�P�U
};