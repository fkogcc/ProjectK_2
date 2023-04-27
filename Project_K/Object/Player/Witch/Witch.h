#pragma once

#include "../Base/PlayerBase.h"


class Witch : public PlayerBase
{
public:
    Witch();
    virtual ~Witch();

    void Init();// 初期化
    void End();// 終了処理
    void Update();// 更新処理
    void Draw();// 描画処理
private:
    int m_handle;// プレイヤーの画像
    
    int m_imgSizeX;
    int m_imgSizeY;

    int m_imgX;// Xのアニメーション
    int m_imgY;// Xのアニメーション


};

