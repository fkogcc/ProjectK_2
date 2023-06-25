#include "Sound.h"
#include <DxLib.h>
#include <vector>

namespace
{
	// �T�E���h�n���h��
	std::vector<int>	m_soundHandle;

	// �T�E���h�t�@�C����
	const char* const kFileName[Sound::SoundId_Num] =
	{
		// BGM
		"Data/Sound/BGM/Title.mp3",
		"Data/Sound/BGM/Select.mp3",
		"Data/Sound/BGM/Main.mp3",
		"Data/Sound/BGM/Result.mp3",

		// SE
		// �����Ȃ��[
		"Data/Sound/SE/Dinosaur/Bite.mp3",
		"Data/Sound/SE/Dinosaur/Pounce.mp3",
		"Data/Sound/SE/Dinosaur/Scratch.mp3",
		"Data/Sound/SE/Dinosaur/Shot.mp3",

		// �G���t
		"Data/Sound/SE/Elf/61_Hit_03.wav",
		"Data/Sound/SE/Elf/27_sword_miss_1.wav",
		"Data/Sound/SE/Elf/17_orc_atk_sword_2.wav",
		"Data/Sound/SE/Elf/05_door_open_2.mp3",

		// ����ɂ���
		"Data/Sound/SE/Kinnikurou/Attack1.mp3",
		"Data/Sound/SE/Kinnikurou/Attack2.mp3",
		"Data/Sound/SE/Kinnikurou/Attack3.mp3",
		"Data/Sound/SE/Kinnikurou/Attack4.mp3",

		// ����
		"Data/Sound/SE/Witch/iceMagic.mp3",
		"Data/Sound/SE/Witch/iceAttack.mp3",
		"Data/Sound/SE/Witch/chickenwalk.mp3",
		"Data/Sound/SE/Witch/knife.mp3",
		"Data/Sound/SE/Witch/charge.mp3",
	};
}

namespace Sound
{
	void load()
	{
		// �T�E���h�f�[�^�̓ǂݍ���
		for (auto& fileName : kFileName)
		{
			int handle = LoadSoundMem(fileName);
			m_soundHandle.push_back(handle);
		}
	}
	void unload()
	{
		// �T�E���h�f�[�^�̉��
		for (auto& handle : m_soundHandle)
		{
			DeleteSoundMem(handle);
			handle = -1;
		}
	}

	// BGM�̍Đ�
	void startBgm(SoundId id, int volume)
	{
		PlaySoundMem(m_soundHandle[id], DX_PLAYTYPE_BACK, true);
		setVolume(id, volume);
	}
	void stopBgm(SoundId id)
	{
		StopSoundMem(m_soundHandle[id]);
	}
	void loopBgm(SoundId id)
	{
		if(CheckSoundMem(m_soundHandle[id]) != 1)
		{
			PlaySoundMem(m_soundHandle[id], DX_PLAYTYPE_BACK, true);
		}
	}
	// ���ʉ��̍Đ�
	void play(SoundId id)
	{
		PlaySoundMem(m_soundHandle[id], DX_PLAYTYPE_BACK, true);
	}

	// ���ʐݒ�	0~255
	void setVolume(SoundId id, int volume)
	{
		ChangeVolumeSoundMem(volume, m_soundHandle[id]);
	}
}
