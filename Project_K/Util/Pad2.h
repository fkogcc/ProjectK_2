#pragma once

// �R���g���[���[�̓��͏�Ԃ��擾����
namespace Pad2
{
	// �p�b�h�̓��͏�Ԏ擾
	void Update();

	// ������������
	bool IsPress(int button);
	// �g���K�[����
	bool IsTrigger(int button);
	// ����������
	bool IsRelase(int button);
}
