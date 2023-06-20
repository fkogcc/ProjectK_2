#pragma once
#include "../Util/common.h"

// �Q�[���V�[�����N���X
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase() {}

	virtual void Init        () {			   }// ������
	virtual void End         ()	{			   }// �I��
	virtual SceneBase* Update() { return this; }// ���t���[���̏���
	virtual void Draw        ()	{              }// �`��

	// �t�F�[�h�֘A
	void UpdateFade();// �t�F�[�h�X�V
	void DrawFade() const;// �t�F�[�h�`��
	bool IsFadingIn() const;// �t�F�[�h�C����
	bool IsFadingOut() const;// �t�F�[�h�A�E�g��
	bool IsFading() const { return IsFadingIn() || IsFadingOut(); }// �t�F�[�h�C��or�A�E�g��

	void StartFadeOut();// �t�F�[�h�A�E�g�J�n

protected:
	// �t�F�[�h�֘A����
	int m_fadeColor;
	int m_fadeBright;
	int m_fadeSpeed;

	bool m_isFadeOut;// �t�F�[�h�A�E�g���s���Ă��邩�ǂ���

	bool m_isBackScene;
};

