#include "Pad2.h"
#include <DxLib.h>

namespace
{
	constexpr int kLogNum = 16;
	// ���̓��O	0���ŐV�̏��
	int padLog[kLogNum];
}

namespace Pad2
{
	// �p�b�h�̓��͏�Ԏ擾
	void update()
	{
		// ���݂̃p�b�h�̏�Ԃ��擾
		int padState = GetJoypadInputState(DX_INPUT_PAD2);

		// ���O�̍X�V
		for (int i = kLogNum - 1; i >= 1; i--)
		{
			padLog[i] = padLog[i-1];
		}
		// �ŐV�̏��
		padLog[0] = padState;
	}

	// ������������
	bool isPress(int button)
	{
		return (padLog[0] & button);
	}
	// �g���K�[����
	bool isTrigger(int button)
	{
		bool isNow = (padLog[0] & button);	// ���݂̏��
		bool isLast = (padLog[1] & button);	// �P�t���[���O�̏��
		return (isNow && !isLast);
	}
	// ����������
	bool isRelase(int button)
	{
		bool isNow = (padLog[0] & button);	// ���݂̏��
		bool isLast = (padLog[1] & button);	// �P�t���[���O�̏��
		return (!isNow && isLast);
	}
}