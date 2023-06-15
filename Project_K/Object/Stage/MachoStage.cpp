#include "MachoStage.h"
#include <DxLib.h>
#include "../../Util/game.h"

namespace
{
	// �e�N�X�`�����
	const char* kMachoBgFileName = "Data/Image/Stage/macho/city.png";
}

MachoStage::MachoStage() :
	m_handle(-1)// �O���t�B�b�N�n���h���̏�����
{
}

MachoStage::~MachoStage()
{

}

void MachoStage::Init()
{
	//�O���t�B�b�N�̃��[�h
	m_handle = LoadGraph(kMachoBgFileName);
}

void MachoStage::Update()
{
	// �����Ȃ�
}

void MachoStage::Draw()
{
	// �g��`��
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_handle, false);
}
