#pragma once

// �T�E���h�֘A����
namespace Sound
{
	typedef enum SoundId
	{
		// BGM
		TitleBgm,		// �^�C�g����ʂ�BGM
		SelectBgm,		// �I����ʂ�BGM
		MainBgm,		// �퓬��ʂ�BGM
		ResultBgm,		// ���U���g��ʂ�BGM

		SoundId_Num
	}SoundId;

	// ���[�h�A�A�����[�h
	void load();
	void unload();

	// BGM�̍Đ�
	void startBgm(SoundId id, int volume = 255);
	void stopBgm(SoundId id);
	void loopBgm(SoundId id);

	// ���ʉ��̍Đ�
	void play(SoundId id);

	// ���ʐݒ�	0~255
	void setVolume(SoundId id, int volume);
}


