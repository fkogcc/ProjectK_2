#include "Pad.h"
#include "DxLib.h"

namespace
{
	constexpr int kLogNum = 16;
	// ���̓��O	0���ŐV�̏��
	int padLog1[kLogNum];

	int padLog2[kLogNum];
}

namespace Pad
{
	// �p�b�h�̓��͏�Ԏ擾
	void Update()
	{
		// ���݂̃p�b�h�̏�Ԃ��擾
		int padState1 = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// ���O�̍X�V
		for (int i = kLogNum - 1; i >= 1; i--)
		{
			padLog1[i] = padLog1[i-1];
		}
		// �ŐV�̏��
		padLog1[0] = padState1;


		// ���݂̃p�b�h�̏�Ԃ��擾
		int padState2 = GetJoypadInputState(DX_INPUT_PAD2);

		// ���O�̍X�V
		for (int i = kLogNum - 1; i >= 1; i--)
		{
			padLog2[i] = padLog2[i - 1];
		}
		// �ŐV�̏��
		padLog2[0] = padState2;
	}

	// ������������
	bool IsPress(int button,int padNum)
	{
		if(padNum == 1) return (padLog1[0] & button);
			
		if(padNum == 2)return (padLog2[0] & button);
	}
	// �g���K�[����
	bool IsTrigger(int button, int padNum)
	{
		bool isNow = false;	// ���݂̏��
		bool isLast = false;	// �P�t���[���O�̏��

		if (padNum == 1)
		{
			isNow = (padLog1[0] & button);
			isLast = (padLog1[1] & button);
		}

		if (padNum == 2)
		{
			isNow = (padLog2[0] & button);
			isLast = (padLog2[1] & button);
		}


		return (isNow && !isLast);
	}
	// ����������
	bool IsRelase(int button, int padNum)
	{
		bool isNow = false;	// ���݂̏��
		bool isLast = false;	// �P�t���[���O�̏��

		if (padNum == 1)
		{
			isNow = (padLog1[0] & button);
			isLast = (padLog1[1] & button);
		}

		if (padNum == 2)
		{
			isNow = (padLog2[0] & button);
			isLast = (padLog2[1] & button);
		}

		return (!isNow && isLast);
	}
}