#include "Witch.h"
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
#include"WitchDead.h"

namespace
{
    const char* const kFilmName = "Data/Image/Player/Witch/Witch.png";// 画像のロード
    const int kShiftX = 100;// 魔女の画像サイズが違うのでその分ずらすための変数
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
    m_playerjudge(0),
    m_shiftX(0),
    m_temp(),
    m_animeFlag(false),
    m_emptyAttackLeft(0),
    m_emptyAttackTop(0),
    m_emptyAttackRight(0),
    m_emptyAttackBottom(0),
    m_jumpFlag(false),
    m_jumpPower(5),
    m_emptyCheckFlag(false),
    m_tempFlag1(false),
    m_tempFlag2(false),
    m_movement(0)
{
    m_pIdle = new WitchIdle;
    m_pRun = new WitchRun;
    m_pShot = new WitchShotAttack;
    m_pLongShot = new WitchLongShotAttack;
    m_pCharge = new WitchCharge;
    m_pChicken = new Chicken;
    m_pKnightCat = new KnightCat;
    m_pDead = new WitchDead;
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
    delete m_pDead;

    my::MyDeleteGraph(m_handle);
}

void Witch::Init()
{
    m_pos = { 100.0f,650.0f };
    m_handle = my::MyLoadGraph(kFilmName);

    m_pIdle->Init();
    m_pRun->Init();
    m_pShot->Init();
    m_pLongShot->Init();
    m_pCharge->Init();
    m_pChicken->Init();
    m_pKnightCat->Init();
    m_pDead->Init();
}

void Witch::Update()
{
    UpdateAttackJudge();
    UpdatePlayerJudge();

    m_pChicken->Update();
    m_pKnightCat->Update();


    // 死亡したら攻撃できなくする
    if (m_hp <= 0)
    {
        m_moveType = static_cast<int>(moveType::Dead);// 走り状態
    }
    if (m_moveType == static_cast<int>(moveType::Dead))
    {
        UpdateDead();
    }
    else
    {
        UpdateAnim();
    }
    if (m_jumpFlag)
    {
        UpdateJump();
    }
    if (!m_animeFlag && !m_jumpFlag)
    {
        UpdateInputKey();
        UpdatePlayerState();
    }
}

void Witch::Draw()
{
    my::MyDrawRectRotaGraph(static_cast<int>(m_pos.x),
        static_cast<int>(m_pos.y),// 表示座標
        48 * m_animeWidth, 48 * m_animeHight,// 切り取り左上
        48 * m_indexX, 48,// 幅、高さ
        3.0f, 0.0f,	// 拡大率、回転角度
        m_handle, true, m_reversal);


    m_pChicken->Draw();
    m_pKnightCat->Draw();

    // デバッグ描画
#if _DEBUG
    //DrawBox(static_cast<int> (m_pos.x) + m_sizeLeft,
    //    static_cast<int> (m_pos.y) + m_sizeTop,
    //    static_cast<int> (m_pos.x) + m_sizeRight,
    //    static_cast<int> (m_pos.y) + m_sizeBottom,
    //    0x00ff00, false);

    //if (m_attackFlag)
    //{
    //    DrawBox(m_attackSizeLeft,
    //        m_attackSizeTop,
    //        m_attackSizeRight,
    //        m_attackSizeBottom,
    //        0xff0000, false);
    //}

    if (m_attackFlag)
    {
        DrawBox(static_cast<int> (m_pos.x) + m_attackSizeLeft,
            static_cast<int> (m_pos.y) + m_attackSizeTop,
            static_cast<int> (m_pos.x) + m_attackSizeRight,
            static_cast<int> (m_pos.y) + m_attackSizeBottom,
            0xff0000, false);
    }
#endif
}

void Witch::UpdateInputKey()
{
    if (Pad::IsPress(PAD_INPUT_RIGHT, m_padNum))
    {
        m_pos.x += 10;
        m_reversal = false;
        m_moveType = static_cast<int>(moveType::Run);// 走り状態
    }
    else if (Pad::IsPress(PAD_INPUT_LEFT, m_padNum))
    {
        m_pos.x -= 10;
        m_reversal = true;
        m_moveType = static_cast<int>(moveType::Run);// 走り状態
    }
    if (Pad::IsPress(PAD_INPUT_UP, m_padNum))
    {
        m_temp = m_pos.y - 150;
        m_jumpFlag = true;
    }
    if (Pad::IsPress(PAD_INPUT_UP, m_padNum) && Pad::IsPress(PAD_INPUT_LEFT, m_padNum))
    {
        m_temp = m_pos.y - 150;
        m_vec.y = m_pos.x - 100;
        m_movement = -10;
        m_jumpFlag = true;
    }
    if (Pad::IsPress(PAD_INPUT_UP, m_padNum) && Pad::IsPress(PAD_INPUT_RIGHT, m_padNum))
    {
        m_temp = m_pos.y - 150;
        m_vec.y = m_pos.x - 100;
        m_movement = 10;
        m_jumpFlag = true;
    }
    if (!m_tempFlag1 && !m_tempFlag2)
    {
        //小攻撃
        if (Pad::IsTrigger(PAD_INPUT_1, m_padNum))
        {
            m_moveType = static_cast<int>(moveType::Attack1);// 攻撃1状態
            m_animeFlag = true;
            m_emptyCheckFlag = true;
            if (m_reversal)
            {
                m_playerjudge = 20;
                m_emptyAttackLeft = 20 - 100;
                m_emptyAttackTop = -20;
                m_emptyAttackRight = 80 - 100;
                m_emptyAttackBottom = 60;
            }
            else
            {
                m_playerjudge = -20;
                m_emptyAttackLeft = 20;
                m_emptyAttackTop = -20;
                m_emptyAttackRight = 80;
                m_emptyAttackBottom = 60;
            }
        }
        //中攻撃
        else if (Pad::IsTrigger(PAD_INPUT_2, m_padNum))
        {
            m_moveType = static_cast<int>(moveType::Attack2);// 攻撃2状態
            m_animeFlag = true;
            m_emptyCheckFlag = true;
            m_pLongShot->SetReversal(m_reversal);
            if (m_reversal)
            {
                m_pos.x -= kShiftX;
                m_playerjudge = 100;
                m_emptyAttackLeft = -140;
                m_emptyAttackTop = -20;
                m_emptyAttackRight = 50;
                m_emptyAttackBottom = 80;
            }
            else
            {
                m_pos.x += kShiftX;
                m_playerjudge = -100;
                m_emptyAttackLeft = -50;
                m_emptyAttackTop = -20;
                m_emptyAttackRight = 140;
                m_emptyAttackBottom = 80;
            }
        }
        //中攻撃
        else if (Pad::IsTrigger(PAD_INPUT_3, m_padNum))
        {
            m_moveType = static_cast<int>(moveType::Attack3);// 攻撃3状態
            m_animeFlag = true;
            m_animeLoopCount = 2;
        }
        //強攻撃
        else if (Pad::IsTrigger(PAD_INPUT_4, m_padNum))
        {
            m_moveType = static_cast<int>(moveType::Attack4);// 攻撃4状態
            m_animeFlag = true;
            m_animeLoopCount = 3;
        }
    }
}

void Witch::UpdatePlayerState()
{
    if (m_moveType == static_cast<int>(moveType::Idol))
    {
        m_animeWidth = m_pIdle->IndexX();
        m_animeMax = m_pIdle->AnimeMax();
        m_emptyCheckFlag = false;
    }
    if (m_moveType == static_cast<int>(moveType::Run))
    {
        m_animeWidth = m_pRun->IndexX();
        m_animeMax = m_pRun->AnimeMax();
        m_emptyCheckFlag = false;
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
    if (m_moveType == static_cast<int>(moveType::Damage))
    {

    }
    if (m_moveType == static_cast<int>(moveType::Dead))
    {
        m_animeWidth = m_pDead->IndexX();
        m_animeHight = m_pDead->IndexY();
        m_animeMax = m_pDead->AnimeMax();
        m_animeFlag = true;
    }
}

void Witch::UpdatePlayerJudge()
{
    m_sizeLeft = static_cast<int>(-30 + m_playerjudge);
    m_sizeTop = static_cast<int>(-40);
    m_sizeRight = static_cast<int>(30 + m_playerjudge);
    m_sizeBottom = static_cast<int>(40);
}

void Witch::UpdateAttackJudge()
{
    //あたりはんてい
    m_attackFlag = m_emptyCheckFlag;
    if (m_tempFlag1)
    {
        m_attackFlag = m_tempFlag1;
    }

    DrawFormatString(200, 0, 0xffffff, "%d", m_attackSizeLeft);

    if (m_attackFlag)
    {
        m_attackSizeLeft = static_cast<int>(m_emptyAttackLeft);
        m_attackSizeTop = static_cast<int>(m_emptyAttackTop);
        m_attackSizeRight = static_cast<int>(m_emptyAttackRight);
        m_attackSizeBottom = static_cast<int>(m_emptyAttackBottom);
    }
    else
    {
        m_attackSizeLeft = 0;
        m_attackSizeTop = 0;
        m_attackSizeRight = 0;
        m_attackSizeBottom = 0;
    }
}

void Witch::UpdateAnim()
{
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
            m_playerjudge = 0;
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
                    m_attackFlag = true;
                }
                m_pChicken->SetFlag(true);
            }
            if (m_moveType == static_cast<int>(moveType::Attack4))
            {
                if (!m_pKnightCat->IsExist())
                {
                    m_pKnightCat->SetReversal(m_reversal);;
                    m_pKnightCat->SetPos(m_pos);
                    m_attackFlag = true;
                }
                m_pKnightCat->SetFlag(true);
            }
            m_moveType = static_cast<int>(moveType::Idol);
        }
    }
    //超力業実装だから直したいな
    if (m_pChicken->IsExist())
    {
        m_attackFlag = true;
        m_emptyAttackLeft = m_pChicken->ReturnPos().x;
        m_emptyAttackTop = m_pChicken->ReturnPos().y - 50;
        m_emptyAttackRight = m_pChicken->ReturnPos().x + 60;
        m_emptyAttackBottom = m_pChicken->ReturnPos().y + 50;
    }
    else if (m_pKnightCat->IsExist())
    {
        m_attackFlag = true;
        m_emptyAttackLeft = 60;
        m_emptyAttackTop = 0;
        m_emptyAttackRight = 120;
        m_emptyAttackBottom = 80;
    }
    m_tempFlag2 = m_pChicken->IsExist();
    m_tempFlag1 = m_pKnightCat->IsExist();
}

void Witch::UpdateDead()
{
    m_animeFrame++;
    if (m_animeFrame > 10)
    {
        m_animeHight++;
        m_animeFrame = 0;
    }
    if (m_animeHight >= m_animeMax)
    {
        m_animeHight = m_animeMax;
    }
}

void Witch::UpdateJump()
{
    m_pos.y -= m_jumpPower;
    m_pos.x += m_movement;
    if (m_pos.y < (m_temp))
    {
        m_jumpPower = -7;
    }

    if (m_pos.y > m_temp + 150)
    {
        m_jumpFlag = false;
        m_pos.y = m_temp + 150;
        m_jumpPower = 5;
        m_movement = 0;
    }
}
