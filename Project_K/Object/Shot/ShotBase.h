#pragma once
#include"../../Util/Vec2.h"
#include"../../Util/game.h"
class ShotBase
{
protected:
	struct Data
	{
		Vec2 Pos;
		Vec2 Vec;

		int shotSizeLeft = 0;
		int shotSizeTop = 0;
		int shotSizeRight = 0;
		int shotSizeBottom = 0;
	};

	Data m_Shot;

	bool m_Exist = false; // ���݂��邩�ǂ���
	bool m_NullShot = false;	  // NullShot�ł��邩�ǂ���

	int m_handle = -1; //�V���b�g�n���h��

	int m_imageNum = 0; //�摜�ԍ�
	int m_imageMaxNum; //�摜�ő�ԍ�
	Vec2 m_imageSize;//�摜�T�C�Y
	int m_changeSpeed = 0; //�摜�ύX�X�s�[�h
	int m_changeFrame;//�摜�ύX�t���[��
	float m_imageScale = 1.0f;// �摜�S�̂̑傫��
	bool m_isTrans = true;// �摜�̔��]

	void ChangeImage();//�摜�ύX

public:
	ShotBase();

	virtual ~ShotBase();

	virtual void Update();
	virtual void Draw();

	virtual Vec2 GetPos() { return m_Shot.Pos; }
	virtual int GetSizeLeft() { return m_Shot.shotSizeLeft; }
	virtual int GetSizeTop() { return m_Shot.shotSizeTop; }
	virtual int GetSizeRight() { return m_Shot.shotSizeRight; }
	virtual int GetSizeBottom() { return m_Shot.shotSizeBottom; }

	virtual bool IsExist();

	virtual bool GetExist() { return m_Exist; }
	bool SetExist() { 
		m_Exist = false; 
		return m_Exist; 
	}

	virtual bool GetNullShot() { return m_NullShot; }

	void SetHandle(int handle) { m_handle = handle; }
	void IsSetDir(bool isTrans) { m_isTrans = isTrans; }


};

