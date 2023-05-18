#pragma once

// �T�E���h�֘A����
namespace Sound
{
	typedef enum SoundId
	{
		// BGM
		SoundId_PlayerShot1,		// �擪��ʂ�BGM
		SoundId_PlayerShot2,	    // ���s��ʂ�BGM

		// ���ʉ�
		SoundId_PlayerShot,		    // �v���C���[���ˉ�
		SoundId_PlayerReload,		// �v���C���[�����[�h
		SoundId_PlayerShot3,		// �v���C���[������
		SoundId_PlayerShot4,	    // ������(����)
		SoundId_PlayerShot5,		// �G�̓o�ꉹ

		SoundId_Num
	}SoundId;

	// ���[�h�A�A�����[�h
	void load();
	void unload();

	// BGM�̍Đ�
	void startBgm(SoundId id, int volume = 255);
	void stopBgm(SoundId id);

	// ���ʉ��̍Đ�
	void play(SoundId id);

	// ���ʐݒ�	0~255
	void setVolume(SoundId id, int volume);
}


