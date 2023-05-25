#pragma once
class StageBase
{
public:
	StageBase();
	~StageBase();

	void Init();
	void Update();
	void Draw();
protected:
	int m_handle;

};

