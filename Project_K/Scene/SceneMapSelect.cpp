#include "SceneMapSelect.h"

SceneMapSelect::SceneMapSelect()
{
}

SceneMapSelect::~SceneMapSelect()
{
}

void SceneMapSelect::Init()
{
}

void SceneMapSelect::End()
{
}

SceneBase* SceneMapSelect::Update()
{
	return this;
}

void SceneMapSelect::Draw()
{
	DrawString(0, 0, "MapSelect", Color::kWhite);
}
