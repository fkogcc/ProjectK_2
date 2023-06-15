#pragma once
class StageBase
{
public :
	StageBase();			// �R���X�g���N�^
	virtual ~StageBase();	// �f�X�g���N�^

	void Init();	// ������
	void Update();	// �X�V
	void Draw();	// �`��

	int GetStartX() const { return m_startX; }	// �n�_���WX�̎擾
	int GetStartY() const { return m_startY; }	// �n�_���WY�̎擾
	int GetEndX() const { return m_endX; }		// �I�_���WX�̎擾
	int GetEndY() const { return m_endY; }		// �I�_���WY�̎擾

protected :
	int m_handle;	// �O���t�B�b�N�n���h��
	int m_bgHandle;	// �w�i�p�O���t�B�b�N�n���h��

	int m_startX;	// �n�_�̍��WX
	int m_startY;	// �n�_�̍��WY
	int m_endX;		// �I�_�̍��WX
	int m_endY;		// �I�_�̍��WY
};

