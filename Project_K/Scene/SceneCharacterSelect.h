#pragma once
#include "SceneBase.h"

class CharaChoice;

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
	bool User1();
	bool User2();
private:
	bool m_isDino;// だいなそー
	bool m_isElf;// エルフ
	bool m_isKin;// きんにくろう
	bool m_isWitch;// 魔女

	bool m_isDino2;// だいなそー
	bool m_isElf2;// エルフ
	bool m_isKin2;// きんにくろう
	bool m_isWitch2;// 魔女

	CharaChoice* m_CharaChoice;
};

