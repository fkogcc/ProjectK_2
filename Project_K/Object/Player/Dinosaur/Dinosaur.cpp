#include "Dinosaur.h"
#include "../../../condition.h"
#include "DinosaurStateManager.h"
#include"../../Shot/ShotBase.h"
#include"../../Shot/Shot.h"

namespace
{
	const char* kFilename = "Data/Image/Player/kyouryuu/Enemy.png";
}

Dinosaur::Dinosaur() : 
	m_Handle(-1)
{
	m_hp = 150;
	m_Handle = LoadGraph(kFilename);
	m_StateManager = new DinosaurStateManager(m_Handle);
	m_StateManager->Init();
	m_Shot.push_back(new Shot(m_pos, { 10,0 }));
}

Dinosaur::~Dinosaur()
{
}

void Dinosaur::Init()
{
}

void Dinosaur::End()
{
}

void Dinosaur::Update()
{
	Pad::update();

	m_StateManager->Update();

	m_pos = m_StateManager->GetPos();

	for (auto& pShot : m_Shot)
	{
		pShot->Update();
	}

	if (m_StateManager->GetshotFlag())
	{
		m_Shot.push_back(new Shot(m_pos, {10,0}));
	}
}

void Dinosaur::Draw()
{
	m_StateManager->Draw();

	for (auto& pShot : m_Shot)
	{
		pShot->Draw();
	}
}
