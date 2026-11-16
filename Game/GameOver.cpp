#include "stdafx.h"
#include "GameOver.h"
#include "Game.h"
#include "Title.h"

GameOver::GameOver()
{
	bgRender.Init("Assets/sprite/GameOver_BG.DDS",1920,1080);
	logoRender.Init("Assets/sprite/GameOver_Logo.DDS",1024,256);
	logoRender.SetPosition(Vector3(0.0f, 200.0f, 0.0f));
	logoRender.Update();
	restartRender.Init("Assets/sprite/Menu_Restart.DDS",512,128);
	restartRender.SetPosition(Vector3(0.0f, -80.0f, 0.0f));
	restartRender.Update();
	menuRender.Init("Assets/sprite/Menu_MainMenu.DDS",512,128);
	menuRender.SetPosition(Vector3(0.0f, -200.0f, 0.0f));
	menuRender.Update();
	cursorRender.Init("Assets/sprite/Menu_Cursor.DDS",64,64);
	cursorRender.SetPosition(Vector3(-270.0f, -80.0f, 0.0f));
	cursorRender.Update();

}

GameOver::~GameOver()
{

}

void GameOver::Update()
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

void GameOver::Render(RenderContext& rc)
{
	bgRender.Draw(rc);
	logoRender.Draw(rc);
	restartRender.Draw(rc);
	menuRender.Draw(rc);
	cursorRender.Draw(rc);

}
