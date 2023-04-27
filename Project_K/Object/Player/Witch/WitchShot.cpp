#include "WitchShot.h"

namespace
{
	constexpr int kAttack_X = 6;
	constexpr int kAttack_Y = 0;
	constexpr int kAnimeMax = 7;
}

void WitchShot::Update()
{
	m_frameCount++;
	if (m_frameCount == 3)//3フレームに一回画像描画位置を変更する
	{
		m_frameCount = 0;
		m_imagePosY++;
	}
	if (m_imagePosY > kAnimeMax)
	{
		m_imagePosY = 0;
	}
}
