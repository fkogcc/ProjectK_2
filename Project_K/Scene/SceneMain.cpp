#include "SceneMain.h"
#include "../Object/Player/Elf/Elf.h"
#include "../Util/DrawFunctions.h"
#include "../condition.h"
#include <assert.h>

#include <iostream>

SceneMain::SceneMain(bool player1, bool player2, bool player3, bool player4) :
	m_pElf(nullptr)
{
	m_pElf = new Elf;
}

SceneMain::~SceneMain()
{
	delete m_pElf;
	m_pElf = nullptr;
}

void SceneMain::Init()
{

}

void SceneMain::End()
{
}

SceneBase* SceneMain::Update()
{
	
	return this;
}

void SceneMain::Draw()
{
	
}