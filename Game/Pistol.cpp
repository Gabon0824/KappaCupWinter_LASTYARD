#include "stdafx.h"
#include "Pistol.h"
#include "Player.h"
Pistol::Pistol()
{
	modelRender.Init("Assets/Chara_wepon/Pistol_Hand.tkm",nullptr,0, enModelUpAxisY);
}
Pistol::~Pistol()
{

}


bool Pistol:: Start()
{
	player = FindGO<Player>("player");
	handBoneId = player->modelRender.FindBoneID(L"hand_r");
	return true;
}

void Pistol:: Update()
{

	Bone* handBone = player->modelRender.GetBone(handBoneId);
	
	Vector3 pos;
	Quaternion rot;
	Vector3 scale;
	handBone->CalcWorldTRS(pos, rot, scale);

	modelRender.SetPosition(pos);
	modelRender.SetRotation(rot);
	modelRender.Update();
}

void  Pistol::Render(RenderContext &rc)
{
	modelRender.Draw(rc);
}