#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

class Stage;		// �X�e�[�W
class PlayerBase;
class Collision;
class UI;			// UI

class SceneMain : public SceneBase
{
public:
	SceneMain(PlayerBase* Player1, PlayerBase* Player2);
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	void UpdateCountDown(); //�����J�n�O�̃J�E���g
	void UpdateMain();//�����J�n
	void UpdateDead();//�Е������񂾂�
private:
	Stage* m_pStage;
	PlayerBase* m_pPlayer[2];
	Collision* m_pColl;
	UI* m_pUi;

	bool m_isVictory1P;// 1P�̏��s
	bool m_isVictory2P;// 2P�̏��s

	void (SceneMain::*m_updateFunc)();

	int countDown; //�J�E���g�_�E��

	int m_font = 0;// �t�H���g�n���h��
};


	