#include "FontFunction.h"
#include"DxLib.h"

// �t�H���g�ǂݍ���
void font::MyFontPath(const TCHAR* path)
{
	LPCTSTR font_path = reinterpret_cast<LPCTSTR>(path); // �ǂݍ��ރt�H���g�t�@�C���̃p�X

	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	//�t�H���g�̓ǂݍ��݂����s������ǂݍ��ݎ��s���o��
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
}