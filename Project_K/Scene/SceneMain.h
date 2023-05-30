#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

#include <fstream>
#include <string>
#include <vector>

// �|�C���^
class Dinosaur;		// ঒���
class Elf;			// �G���t
class Kinnikurou;	// �ؓ�
class Witch;		// ����
class PlayerBase;
class Collision;

class Stage;		// �X�e�[�W

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
	Stage*		m_pStage;

	PlayerBase* m_Player[2];

	Collision* m_Coll;

	bool m_isVictory1P;// 1P�̏��s
	bool m_isVictory2P;// 2P�̏��s
};


	