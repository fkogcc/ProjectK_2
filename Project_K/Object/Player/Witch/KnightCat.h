#pragma once
#include "../Base/MoveTypeBase.h"
class KnightCat :
	public MoveTypeBase
{
public:
	KnightCat();// �R���X�g���N�^
	virtual ~KnightCat();// �f�X�g���N�^
	void Init();// ������
	void Update();// �X�V����
	void Draw(float sizeup);// �`�揈��

	void SetReversal(bool reversal) { m_reversal = reversal; }// ���]���Ă��邩
	void SetPos(Vec2 pos) { m_pos = pos; }// �v���C���[�̈ʒu
	void SetFlag(bool flag) { m_exist = flag; }// ���݂��Ă��邩�̃t���O���Z�b�g
	bool IsExist() { return m_exist; }// ���݂��Ă��邩�̃t���O
	float GetMovePos() { return m_movePos; }// �L�����̈ʒu
	Vec2 GetPos() { return m_pos; }// �v���C���[�̈ʒu���L������
private:
	int m_handle;// �摜
	bool m_reversal;// ���]
	Vec2 m_pos;// �ʒu
	float m_movePos;// �������ʒu
	int m_timeCount;// �����^�̃J�E���g������ϐ�
	int m_animeFrame;// �t���[��
	int m_animeMax;// �A�j���[�V�����̖����ԍ�
	int m_animeWidth;// �A�j���[�V�����̂���
	int m_animeHight;// �A�j���[�V�����̒n��
	bool m_exist;// ����
};

