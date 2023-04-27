#include "Witch.h"
#include "../../condition.h"
#include "../../Util/DrawFunctions.h"

namespace
{
	const char* const kWitchHandle = "Data/Image/Player/Witch/Witch.png";
}

Witch::Witch() :
	m_handle(0),
	m_imgSizeX(0),
	m_imgSizeY(0),
	m_imgX(0),
	m_imgY(0)
{
}

Witch::~Witch()
{
}

void Witch::Init()
{
	// 初期化処理
	m_handle = my::MyLoadGraph(kWitchHandle);
	m_imgSizeX = 48;
	m_imgSizeY = 48;
}

void Witch::End()
{
	// 画像の消去
	my::MyDeleteGraph(m_handle);
}

void Witch::Update()
{
}

void Witch::Draw()
{
	// キャラクターの描画
	if (m_moveType == static_cast<int>(moveType::Idol))
	{
		my::MyDrawRectRotaGraph(0, 0,
			m_imgX * m_imgSizeX, m_imgY * m_imgSizeY,
			m_imgSizeX, m_imgSizeY,
			2.0f, 0.0f,
			m_handle,
			true, false);
	}
}
