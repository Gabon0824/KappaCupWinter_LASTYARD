#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"


GameClear::GameClear()
{
	clearRender.Init("Assets/sprite/Clear_BG.DDS", 1920, 1080);
	spriteRender.Init("Assets/sprite/Clear_Logo.DDS", 1024, 256);
	spriteRender.SetPosition(Vector3(0.0f, 230.0f, 0.0f));
	spriteRender.Update();
}

GameClear::~GameClear()
{

}

void GameClear :: Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "Title");
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc)
{
	clearRender.Draw(rc);
	spriteRender.Draw(rc);
}
