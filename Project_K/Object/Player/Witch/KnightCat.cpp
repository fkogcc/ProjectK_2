#include "KnightCat.h"
#include "../../Util/DrawFunctions.h"
namespace
{
	const char* const kFilmName = "Data/Image/Player/Witch/Nekochan.png";
}
KnightCat::KnightCat() :
	m_handle(0),
	m_reversal(false),
	m_pos(),
	m_animeFrame(0),
	m_animeMax(0),
	m_animeWidth(0),
	m_animeHight(0),
	m_exist(false),
	m_timeCount(0)
{

}

KnightCat::~KnightCat()
{
	my::MyDeleteGraph(m_handle);
}

void KnightCat::Init()
{
	m_animeWidth = 2;
	m_animeHight = 0;
	m_animeMax = 4;
	m_handle = my::MyLoadGraph(kFilmName);
}

void KnightCat::Update()
{
	if (m_exist)
	{
		m_animeFrame++;
		m_timeCount++;
		if (m_animeFrame > 10)
		{
			m_animeHight++;
			m_animeFrame = 0;
		}
		if (m_animeHight >= m_animeMax)
		{
			m_animeHight = 0;
		}
		if (m_timeCount > 60 * 3)
		{
			m_exist = false;
			m_timeCount = 0;
		}
	}
}

void KnightCat::Draw()
{
	if (m_exist)
	{
		my::MyDrawRectRotaGraph(static_cast<int>(m_pos.x) + 20,
			static_cast<int>(m_pos.y),			//表示座標
			32 * m_animeWidth, 32 * m_animeHight,			//切り取り左上
			32, 32,							//幅、高さ
			3.0f, 0.0f,						//拡大率、回転角度
			m_handle, true, m_reversal);
	}
}

void KnightCat::SetPos(Vec2 pos)
{
	m_pos.x = pos.x;
	m_pos.y = pos.y;
}