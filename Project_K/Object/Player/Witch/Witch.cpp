#include "Witch.h"
#include"../../Util/Pad.h"
#include"../../Util/game.h"
#include "../../Util/DrawFunctions.h"
#include "../../condition.h"
#include"WitchIdle.h"
#include"WitchRun.h"
#include"WitchShotAttack.h"
#include"WitchLongShotAttack.h"
#include"WitchCharge.h"
#include"Chicken.h"
#include"KnightCat.h"

namespace
{
	const char* const kFilmName = "Data/Image/Player/Witch/Witch.png";
}

Witch::Witch() :
    m_handle(0),
    m_animeHight(0),
    m_animeWidth(0),
    m_reversal(false),
    m_imageX(0),
    m_imageY(0),
    m_animeLoopCount(1),
    m_LoopCount(1),
    m_animeFrame(0),
    m_animeMax(0),
    m_indexX(0),
    m_shiftX(0),
    m_animeFlag(false)
{
    m_pIdle = new WitchIdle;
    m_pRun = new WitchRun;
    m_pShot = new WitchShotAttack;
    m_pLongShot = new WitchLongShotAttack;
    m_pCharge = new WitchCharge;
    m_pChicken = new Chicken;
    m_pKnightCat = new KnightCat;
}

Witch::~Witch()
{
    delete m_pIdle;
    delete m_pRun;
    delete m_pShot;
    delete m_pLongShot;
    delete m_pCharge;
    delete m_pChicken;
    delete m_pKnightCat;

    my::MyDeleteGraph(m_handle);
}

void Witch::Init()
{
    m_handle = my::MyLoadGraph(kFilmName);

    m_pIdle->Init();
    m_pRun->Init();
    m_pShot->Init();
    m_pLongShot->Init();
    m_pCharge->Init();
    m_pChicken->Init();
    m_pKnightCat->Init();
}

void Witch::Update()
{
    Pad::Update();
    m_pChicken->Update();
    m_pKnightCat->Update();
    m_animeFrame++;
    if (m_animeFrame > 10)
    {
        m_animeHight++;
        m_animeFrame = 0;
    }
    if (m_animeHight >= m_animeMax)
    {
        m_LoopCount++;
        m_animeHight = 0;
        if (m_LoopCount >= m_animeLoopCount)
        {
            m_indexX = 1;
            m_animeFlag = false;
            if (m_reversal)
            {
               m_shiftX *= -1;
            }
            m_pos.x += m_shiftX;
            m_shiftX = 0;
            m_LoopCount = 0;
            m_animeLoopCount = 1;

            if (m_moveType == static_cast<int>(moveType::Attack3))
            {
                if (!m_pChicken->IsExist())
                {
                    m_pChicken->SetReversal(m_reversal);
                    m_pChicken->SetPos(m_pos);
                }
                m_pChicken->SetFlag(true);
            }
            if (m_moveType == static_cast<int>(moveType::Attack4))
            {
                if (!m_pKnightCat->IsExist())
                {
                    m_pKnightCat->SetReversal(m_reversal);;
                    m_pKnightCat->SetPos(m_pos);
                }
                m_pKnightCat->SetFlag(true);
            }
        }
    }


    if (!m_animeFlag)
    {
        if (Pad::IsPress(PAD_INPUT_RIGHT))
        {
            m_pos.x += 10;
            m_reversal = false;
            m_moveType = static_cast<int>(moveType::Run);// ëñÇËèÛë‘
        }
        if (Pad::IsPress(PAD_INPUT_LEFT))
        {
            m_pos.x -= 10;
            m_reversal = true;
            m_moveType = static_cast<int>(moveType::Run);// ëñÇËèÛë‘
        }
        if (Pad::IsPress(PAD_INPUT_UP))
        {
            m_pos.y -= 10;
        }
        if (Pad::IsPress(PAD_INPUT_DOWN))
        {
            m_pos.y += 10;
        }

        //è¨çUåÇ
        if (Pad::IsTrigger(PAD_INPUT_1))
        {
            m_moveType = static_cast<int>(moveType::Attack1);// çUåÇ1èÛë‘
            m_animeFlag = true;
        }
        //íÜçUåÇ
        else if (Pad::IsTrigger(PAD_INPUT_2))
        {
            m_moveType = static_cast<int>(moveType::Attack2);// çUåÇ2èÛë‘
            m_animeFlag = true;
            m_pos.x += 100;
        }
        else if (Pad::IsTrigger(PAD_INPUT_3))
        {
            m_moveType = static_cast<int>(moveType::Attack3);// çUåÇ3èÛë‘
            m_animeFlag = true;
            m_animeLoopCount = 2;
        }
        else if (Pad::IsTrigger(PAD_INPUT_4))
        {
            m_moveType = static_cast<int>(moveType::Attack4);// çUåÇ4èÛë‘
            m_animeFlag = true;
            m_animeLoopCount = 3;
        }
        else
        {
            m_moveType = static_cast<int>(moveType::Idol);// ÉAÉCÉhÉãèÛë‘
        }


        if (m_moveType == static_cast<int>(moveType::Idol))
        {
            m_animeWidth = m_pIdle->IndexX();
            m_animeMax = m_pIdle->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Run))
        {
            m_animeWidth = m_pRun->IndexX();
            m_animeMax = m_pRun->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack1))
        {
            m_animeWidth = m_pShot->IndexX();
            m_animeHight = m_pShot->IndexY();
            m_animeMax = m_pShot->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack2))
        {
            m_pLongShot->Update();
            m_animeWidth = m_pLongShot->IndexX();
            m_animeHight = m_pLongShot->IndexY();
            m_indexX = m_pLongShot->SizeX();
            m_shiftX = m_pLongShot->ShiftX();
            m_animeMax = m_pLongShot->AnimeMax();
            m_pLongShot->SetReversal(m_reversal);
        }
        if (m_moveType == static_cast<int>(moveType::Attack3))
        {
            m_animeWidth = m_pCharge->IndexX();
            m_animeHight = m_pCharge->IndexY();
            m_animeMax = m_pCharge->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack4))
        {
            m_animeWidth = m_pCharge->IndexX();
            m_animeHight = m_pCharge->IndexY();
            m_animeMax = m_pCharge->AnimeMax();
        }

    }
    ////ëñÇË
    //if (Pad::isTrigger(PAD_INPUT_1))
    //{
    //    m_animeWidth = 1;
    //    m_animeHight = 0;
    //    m_animeMax = 6;
    //}
    ////É_ÉÅÅ[ÉW
    //if (Pad::isTrigger(PAD_INPUT_2))
    //{
    //    //animeNum = 0;
    //    m_animeWidth = 2;
    //    m_animeHight = 0;
    //    m_animeMax = 3;
    //}
    ////éÄñS
    //if (Pad::isTrigger(PAD_INPUT_3))
    //{
    //    m_animeWidth = 3;
    //    m_animeHight = 0;
    //    m_animeMax = 12;
    //}

}

void Witch::Draw()
{
    my::MyDrawRectRotaGraph(static_cast<int>(m_pos.x),
        static_cast<int>(m_pos.y),			//ï\é¶ç¿ïW
        48 * m_animeWidth, 48 * m_animeHight,			//êÿÇËéÊÇËç∂è„
        48 * m_indexX, 48,							//ïùÅAçÇÇ≥
        3.0f, 0.0f,						//ägëÂó¶ÅAâÒì]äpìx
        m_handle, true, m_reversal);
    DrawFormatString(0,0,0x00ff00,"%f",m_pos.x);

    m_pChicken->Draw();
    m_pKnightCat->Draw();
}