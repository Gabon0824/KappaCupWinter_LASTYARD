#include "stdafx.h"
#include "Game.h"
#include "Map.h"





Game::Game()
{
	map = NewGO<Map>(0);
}

Game::~Game()
{
	DeleteGO(map);
}

bool Game::Start()
{
	m_modelRender.Init("Assets/Chara_wepon/Human.tkm");
	
	return true;
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}