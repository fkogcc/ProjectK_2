#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class SceneResult : public SceneBase
{
public:
	/// <summary>
	/// ���s�t���O�t���R���X�g���N�^
	/// </summary>
	/// <param name="isVictoryOrDefeat"></param>
	SceneResult(bool isVictoryOrDefeat);
	virtual ~SceneResult();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	bool m_isTitle;// �^�C�g����
	bool m_isRetry;// ���g���C

	bool m_isNone = false;// �����̒��g���Ȃ����

	bool m_isVictoryOrDefeat;// ���s:true.1P����,false.2P����
};

