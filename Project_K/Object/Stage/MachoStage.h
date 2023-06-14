#pragma once
class MachoStage
{
public:
	MachoStage();
	virtual ~MachoStage();

	void Init();
	void Update();
	void Draw();

private:
	int m_handle;	// グラフィックハンドル
};

