#include "SceneMain.h"
#include "../Object/Player/Dinosaur/Dinosaur.h"
#include "../Object/Player/Elf/Elf.h"
#include "../Object/Player/Kinnikurou/Kinnikurou.h"
#include "../Object/Player/Witch/Witch.h"
#include "../Util/DrawFunctions.h"
#include "../condition.h"
#include <assert.h>

#include <iostream>

SceneMain::SceneMain(bool isDino, bool isElf, bool isKin, bool isWitch) :
	m_pDino(nullptr),
	m_pElf(nullptr),
	m_pKin(nullptr),
	m_pWitch(nullptr),
	m_isDino(true),
	m_isElf(false),
	m_isKin(false),
	m_isWitch(false)
{
	m_pDino = new Dinosaur;
	m_pElf = new Elf;
	m_pKin = new Kinnikurou;
	m_pWitch = new Witch;
}

SceneMain::~SceneMain()
{
	delete m_pDino;
	delete m_pElf;
	delete m_pKin;
	delete m_pWitch;
}

void SceneMain::Init()
{
	if (m_isDino) m_pDino->Init();
	if (m_isElf) m_pElf->Init();
	if (m_isKin) m_pKin->Init();
	if (m_isWitch) m_pWitch->Init();
}

void SceneMain::End()
{
	if (m_isDino) m_pDino->End();
	if (m_isElf) m_pElf->End();
	if (m_isKin) m_pKin->End();
	//if (m_isWitch) m_pWitch->End();
}

SceneBase* SceneMain::Update()
{
	if (m_isDino) m_pDino->Update();
	if (m_isElf) m_pElf->Update();
	if (m_isKin) m_pKin->Update();
	if (m_isWitch) m_pWitch->Update();

	return this;
}

void SceneMain::Draw()
{
	if (m_isDino) m_pDino->Draw();
	if (m_isElf) m_pElf->Draw();
	if (m_isKin) m_pKin->Draw();
	if (m_isWitch) m_pWitch->Draw();
}