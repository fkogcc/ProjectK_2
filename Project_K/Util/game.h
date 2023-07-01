#pragma once

namespace Game
{
#ifdef _DEBUG
	// ウインドウモード設定
	constexpr bool kWindowModo = true;
#else
	constexpr bool kWindowModo = false;
#endif
	//ウィンドウ名
	const char* const kTitleText = "Project_K";
	//ウィンドウサイズ
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;
	//カラーモード
	constexpr int kColorDepth = 32; //３２or１６
};