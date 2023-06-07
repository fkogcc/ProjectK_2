#include "ElfShot.h"

ElfShoot::~ElfShoot()
{
}

void ElfShoot::Update()
{
	m_Shot.Pos += m_Shot.Vec;

	ShotBase::Update();
}
