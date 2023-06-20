#pragma once
#include "SceneBase.h"

class CharaChoice;
class PlayerBase;
class SelectUI;
class SceneCharacterSelect : public SceneBase
{
public:
	SceneCharacterSelect(int StageNo);
	virtual ~SceneCharacterSelect();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	// �v���C���[���L�����N�^�[��I�񂾎�
	//bool IsSelected() { return };

private:
	/*bool User1();
	bool User2();*/
private:
	bool m_isDino;// �����Ȃ��[
	bool m_isElf;// �G���t
	bool m_isKin;// ����ɂ��낤
	bool m_isWitch;// ����

	bool m_isDino2;// �����Ȃ��[
	bool m_isElf2;// �G���t
	bool m_isKin2;// ����ɂ��낤
	bool m_isWitch2;// ����

	int m_stageNo;	// �X�e�[�W�̔ԍ�

	PlayerBase* m_Player[2];

	CharaChoice* m_CharaChoice;
	SelectUI* m_pUi;
};