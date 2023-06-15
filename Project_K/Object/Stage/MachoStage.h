#pragma once
#include "../Stage/StageBase.h"

class MachoStage : public StageBase
{
public:
	MachoStage();

	void Init();
	void Update();
	void Draw();

private:
	int m_handle;	// グラフィックハンドル
};

