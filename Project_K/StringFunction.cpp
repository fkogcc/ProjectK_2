#include "StringFunction.h"
#include <DxLib.h>

//////////////////
// テキスト設定 //
//////////////////
StringFunction::StringFunction()
{

}

StringFunction::~StringFunction()
{
}

void StringFunction::Add(int x, int y, const char* text, int color, int size, const char* font)
{
	m_pAddString.push_back(std::make_shared<AddString>(x,y,text,color,size,font));
}

void StringFunction::Draw()
{
	for (auto& text : m_pAddString)
	{
		text->Draw();
	}
}

//////////////////
// テキスト作成 //
//////////////////
AddString::AddString(int x, int y, const char* text, int color, int size, const char* font) :
	m_x(x),
	m_y(y),
	m_text(text),
	m_color(color),
	m_size(size),
	m_font(font),
	m_fontHandle(-1)
{
	m_fontHandle = CreateFontToHandle(m_font, m_size, 3);
}

AddString::~AddString()
{
}

void AddString::Draw()
{
	DrawStringToHandle(m_x, m_y, m_text, m_color, m_fontHandle);
}
