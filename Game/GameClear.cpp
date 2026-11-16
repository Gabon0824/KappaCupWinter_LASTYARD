#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"


GameClear::GameClear()
{
	clearRender.Init("Assets/sprite/Clear_BG.DDS", 1920, 1080);
	spriteRender.Init("Assets/sprite/Clear_Logo.DDS", 1024, 256);
	spriteRender.SetPosition(Vector3(0.0f, 230.0f, 0.0f));
	spriteRender.Update();
	restartRender.Init("Assets/sprite/Menu_Restart.DDS", 512, 128);
	restartRender.SetPosition(Vector3(0.0f, -80.0f, 0.0f));
	restartRender.Update();
	menuRender.Init("Assets/sprite/Menu_MainMenu.DDS", 512, 128);
	menuRender.SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	menuRender.Update();
	cursorRender.Init("Assets/sprite/Menu_Cursor.DDS", 64, 64);
	cursorRender.SetPosition(Vector3(-270.0f, -80.0f, 0.0f));
	cursorRender.Update();
}

GameClear::~GameClear()
{

}

void GameClear :: Update()
{
	

	if (g_pad[0]->IsTrigger(enButtonDown))
	{
		Select = 1;
	}
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		Select = 0;
	}
	if (Select == 0)
	{
		cursorRender.SetPosition(Vector3(-270.0f, -80.0f, 0.0f));
	}
	else
	{
		cursorRender.SetPosition(Vector3(-270.0f, -200.0f, 0.0f));
	}
	cursorRender.Update();

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		if (Select == 0)
		{
			NewGO<Game>(0, "game");
		}
		else
		{
			NewGO<Title>(0, "titleAA");
		}
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc)
{
	clearRender.Draw(rc);
	spriteRender.Draw(rc);
	restartRender.Draw(rc);
	menuRender.Draw(rc);
	cursorRender.Draw(rc);
}
