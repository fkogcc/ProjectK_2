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
	int m_handle;	// �O���t�B�b�N�n���h��
};

