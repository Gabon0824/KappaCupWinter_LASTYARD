#include "stdafx.h"
#include "Reticle.h"

Reticle::Reticle()
{
	spriteRender.Init("Assets/sprite/Reticle.dds",64,64);

}

Reticle::~Reticle()
{

}
void Reticle:: Update()
{
	spriteRender.Update();
}

void Reticle :: Render(RenderContext &rc)
{
	if (g_pad[0]->IsPress(enButtonLB2))
	{
		spriteRender.Draw(rc);
	}
}