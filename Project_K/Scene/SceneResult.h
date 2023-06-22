#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class PlayerBase;
class StringFunction;
class UIAnimation;
class SceneResult : public SceneBase
{
public:
	/// <summary>
	/// ���s�t���O�t���R���X�g���N�^
	/// </summary>
	/// <param name="isVictoryOrDefeat"></param>
	SceneResult(bool isVictory1P, bool isVictory2P, PlayerBase* player1P, PlayerBase* player2P);
	virtual ~SceneResult();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	// �|�C���^
	PlayerBase* m_pPlayer[2];// �v���C���[�x�[�X
	StringFunction* m_pString;
	UIAnimation* m_pAnimUI;

	bool m_isTitle;// �^�C�g����
	bool m_isRetry;// ���g���C

	bool m_isNone = false;// �����̒��g���Ȃ����

	bool m_isVictory1P;// 1P�̏��s
	bool m_isVictory2P;// 2P�̏��s
};

