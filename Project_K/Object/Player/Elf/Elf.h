#pragma once

#include "../Base/PlayerBase.h"

class ElfIdol;
class Elf : public PlayerBase
{
public:
	Elf();
	~Elf();

	void Init  ();// ‰Šú‰»
	void End   ();// I—¹ˆ—
	void Update();// XV
	void Draw  ();// •`‰æ

private:
	int m_handle;

	int m_imageX, m_imageY;

	ElfIdol* m_pIdle;
};

