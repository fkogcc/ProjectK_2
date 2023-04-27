#include "SceneCharacterSelect.h"
#include "SceneMain.h"

SceneCharacterSelect::SceneCharacterSelect()
{
}

SceneCharacterSelect::~SceneCharacterSelect()
{
}

void SceneCharacterSelect::Init()
{
}

void SceneCharacterSelect::End()
{
}

SceneBase* SceneCharacterSelect::Update()
{

#if true// SceneMainコンストラクタ引数あり
	// m_pSceneMain = new SceneMain(true);
	return(new SceneMain(true, true, true, true));// 1ステージ切り替え
#else	// SceneMainコンストラクタ引数なし
	return(new SceneMain);// 1ステージ切り替え
#endif
	return this;
}

void SceneCharacterSelect::Draw()
{
}
