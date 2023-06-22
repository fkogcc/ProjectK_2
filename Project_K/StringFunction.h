#pragma once
#include <vector>
#include <memory>

class AddString;

//////////////////
// �e�L�X�g�ݒ� //
//////////////////
class StringFunction
{
public:
	StringFunction();
	virtual ~StringFunction();

	/// <summary>
	/// ������ǉ�����
	/// </summary>
	/// <param name="x">���W</param>
	/// <param name="y">���W</param>
	/// <param name="text">����</param>
	/// <param name="color">�F</param>
	/// <param name="size">�傫��</param>
	/// <param name="font">�t�H���g�p�X</param>
	virtual void Add(int x, int y, const char* text, int color, int size, const char* font);

	virtual void Draw();

private:
	std::vector<std::shared_ptr<AddString>>m_pAddString;
};

//////////////////
// �e�L�X�g�쐬 //
//////////////////
class AddString
{
public:
	/// <summary>
	/// ������ǉ�����
	/// </summary>
	/// <param name="x">���W</param>
	/// <param name="y">���W</param>
	/// <param name="text">����</param>
	/// <param name="color">�F</param>
	/// <param name="size">�傫��</param>
	/// <param name="font">�t�H���g�p�X</param>//
	AddString(int x, int y, const char* text, int color, int size, const char* font);
	virtual ~AddString();

	virtual void Draw();
private:
	int m_x;
	int m_y;
	const char* m_text;
	int m_color;
	int m_size;
	const char* m_font;
	int m_fontHandle;
};
