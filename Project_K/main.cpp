#include <DxLib.h>
#include "Util/game.h"
#include "Scene/SceneManager.h"
#include "Util/Sound.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode             (Game::kWindowMode                                         );// window���[�h�ݒ�
	SetMainWindowText            (Game::kTitleText                                          );// �E�C���h�E���ݒ�
	SetGraphMode                 (Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);// ��ʃT�C�Y�̐ݒ�
	SetWindowSizeChangeEnableFlag(true                                                      );// �E�C���h�E���[�h�̎��ɃE�C���h�E�̃T�C�Y�ύX�ł���
	SetAlwaysRunFlag			 (true                                                      );// �E�C���h�E���A�N�e�B�u�ł͂Ȃ���Ԃł������𑱍s����

	if (DxLib_Init() == -1)// �c�w���C�u��������������
	{
		return -1;// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);// �_�u���o�b�t�@���[�h

	// �T�E���h�ǂݍ���
	Sound::load();

	SceneManager scene;
	scene.Init();// �V�[���̏�����

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		
		ClearDrawScreen();// ��ʂ̃N���A

		scene.Update();// �V�[���̍X�V����
		scene.Draw();// �V�[���̕`��

		ScreenFlip();// ����ʂ�\��ʂ����ւ���

		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;// esc�L�[����������I������

		while (GetNowHiPerformanceCount() - time < 16667) {}// fps��60�ɌŒ�
	}

	scene.End();// �V�[���̏I������

	Sound::unload();

	DxLib_End();// �c�w���C�u�����g�p�̏I������

	return 0;// �\�t�g�̏I�� 
}