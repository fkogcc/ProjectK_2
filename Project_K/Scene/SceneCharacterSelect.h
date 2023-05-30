#pragma once
#include "SceneBase.h"

class CharaChoice;
class PlayerBase;

class SceneCharacterSelect : public SceneBase
{
public:
	SceneCharacterSelect();
	virtual ~SceneCharacterSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	PlayerBase* m_Player[2];
	CharaChoice* m_CharaChoice;
};

