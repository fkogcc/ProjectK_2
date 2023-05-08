#include "Shot.h"

Shot::~Shot()
{
}

void Shot::Update()
{
	m_Shot.Pos += m_Shot.Vec;
}
