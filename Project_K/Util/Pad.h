#pragma once

// �R���g���[���[�̓��͏�Ԃ��擾����
namespace Pad
{
	// �p�b�h�̓��͏�Ԏ擾
	void Update();

	// ������������
	bool IsPress(int button, int padNum);
	// �g���K�[����
	bool IsTrigger(int button, int padNum);
	// ����������
	bool IsRelase(int button, int padNum);
}
