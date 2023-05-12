#include "SceneResult.h"

SceneResult::SceneResult()
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Init()
{
}

void SceneResult::End()
{
}

SceneBase* SceneResult::Update()
{
	return this;
}

void SceneResult::Draw()
{
	DrawString(0, 0, "MapSelect", Color::kWhite);
}
