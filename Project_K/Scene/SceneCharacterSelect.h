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
	bool m_isDino;// �����Ȃ��[
	bool m_isElf;// �G���t
	bool m_isKin;// ����ɂ��낤
	bool m_isWitch;// ����

	bool m_isDino2;// �����Ȃ��[
	bool m_isElf2;// �G���t
	bool m_isKin2;// ����ɂ��낤
	bool m_isWitch2;// ����

	CharaChoice* m_CharaChoice;
};

