#include "Chicken.h"
#include"../../Util/game.h"
#include "../../Util/DrawFunctions.h"
namespace
{
	const char* const kFilmName = "Data/Image/Player/Witch/Niwatori.png";
	float kMovePos = 45.0f;
}
Chicken::Chicken() :
	m_handle(0),
	m_movePos(45),
	m_reversal(false),
	m_pos(),
	m_animeFrame(0),
	m_animeMax(0),
	m_animeWidth(0),
	m_animeHight(0),
	m_exist(false)
{

}

Chicken::~Chicken()
{
	my::MyDeleteGraph(m_handle);
}

void Chicken::Init()
{
	m_animeWidth = 1;
	m_animeHight = 0;
	m_animeMax = 10;
	m_handle = my::MyLoadGraph(kFilmName);
}

void Chicken::Update()
{
	if (m_exist)
	{
		m_animeFrame++;
		if (m_reversal && m_movePos == 45)
		{
			m_movePos *= -1;
		}
		if (m_animeFrame > 7)
		{
			m_animeHight++;
			m_pos.x += m_movePos;
			m_animeFrame = 0;
		}
		if (m_animeHight >= m_animeMax)
		{
			m_animeHight = 0;
		}
		if (m_pos.x >= Game::kScreenWidth  ||  m_pos.x <= 0)
		{
			m_exist = false;
		}
	}
	else
	{
		m_movePos = 45;
	}
}

void Chicken::Draw()
{
	if (m_exist)
	{
		my::MyDrawRectRotaGraph(static_cast<int>(m_pos.x) + 30,
			static_cast<int>(m_pos.y),			//表示座標
			32 * m_animeWidth, 32 * m_animeHight,			//切り取り左上
			32, 32,							//幅、高さ
			3.0f, 0.0f,						//拡大率、回転角度
			m_handle, true, m_reversal);
	}
}

void Chicken::SetPos(Vec2 pos)
{
	m_pos.x = pos.x;
	m_pos.y = pos.y;
}