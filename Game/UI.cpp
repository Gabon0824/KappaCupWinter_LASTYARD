#include "stdafx.h"
#include "UI.h"
#include "Pistol.h"
#include "Player.h"
UI::UI()
{
	healthFrame.Init("Assets/sprite/UI_HealthFrame.DDS", 384, 48);
	healthFrame.SetPosition(Vector3(-668.0f, 451.0f, 0.0f));
	healthTicks.Init("Assets/sprite/UI_HealthTicks.DDS", 332, 20);
	healthTicks.SetPosition(Vector3(-650.0f, 447.0f, 0.0f));
	weponPanel.Init("Assets/sprite/UI_WeaponPanel.DDS", 220, 110);
	weponPanel.SetPosition(Vector3(-750.0f, 331.0f, 0.0f));
	medkitPanel.Init("Assets/sprite/UI_MedkitPanel.DDS", 165, 110);
	medkitPanel.SetPosition(Vector3(-536.0f, 331.0f, 0.0f));
	healthBar.Init("Assets/sprite/UI_HealthBar.DDS", 332, 20);
	healthBar.SetPivot(Vector2(0.0f, 0.5f));
	healthBar.SetPosition(Vector3(-816.0f, 447.0f, 0.0f));
	magazineText.SetPosition(Vector3(-728.0f, 336.0f, 0.0f));
	ammoText.SetPosition(Vector3(-677.0f, 324.0f, 0.0f));
	ammoText.SetScale(0.6f);
}
UI::~UI()
{

}

bool UI::Start()
{
	pistol = FindGO<Pistol>("pistol");
	player = FindGO<Player>("player");
	return true;
}
void UI::Update()
{
	//今のHPの割合を知って減らす仕組み
	float hpRate = (float)player->hp / player->MAX_HP;
	healthBar.SetScale(Vector3(hpRate, 1.0f, 1.0f));
	healthFrame.Update();
	healthBar.Update();


	healthFrame.Update();
	healthBar.Update();
	healthTicks.Update();
	weponPanel.Update();
	medkitPanel.Update();
	wchar_t text[32];
	swprintf_s(text, L"%d", pistol->nowMagazine);
	magazineText.SetText(text);
	swprintf_s(text, L"/%d", pistol->ammo);
	ammoText.SetText(text);
}
void UI::Render(RenderContext& rc)
{

	healthFrame.Draw(rc);
	healthBar.Draw(rc);
	healthTicks.Draw(rc);
	weponPanel.Draw(rc);
	medkitPanel.Draw(rc);
	magazineText.Draw(rc);
	ammoText.Draw(rc);
}
