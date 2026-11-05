#include "stdafx.h"
#include "Pistol.h"
#include "Player.h"
#include "Bullet.h"

namespace
{
	const float SHOT_INTERVAL = 0.3f;

	const float BULLET_SPEED = 3000.0f;

	const Vector3 MUZZELE_OFFSET = { -7.13f,0.93f,5.9f };
	//最大弾数
	const int MAGAZINE_SIZE = 10;
	//リロード時間
	const float RELOAD_TIME = 1.5f;


}





Pistol::Pistol()
{
	modelRender.Init("Assets/Chara_wepon/Pistol_Hand.tkm",nullptr,0, enModelUpAxisY);
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/PistolShot.wav");
	EffectEngine::GetInstance()->ResistEffect(2, u"Assets/effect/MuzzleFlash.efk");
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

	coolTime -= g_gameTime->GetFrameDeltaTime();

	if (nowreload == true)
	{
		ReloadTime -= g_gameTime->GetFrameDeltaTime();
		if (ReloadTime <= 0.0f)
		{
			int need = MAGAZINE_SIZE - nowMagazine;
			if (need > ammo) { need = ammo; }
			nowMagazine += need;
			ammo -= need;
			nowreload = false;
		}
	}

	if (coolTime <= 0.0f && g_pad[0]->IsPress(enButtonLB2) && g_pad[0]->IsTrigger(enButtonRB2) && nowMagazine > 0 && nowreload == false)
	{
		Vector3 muzzlePos = MUZZELE_OFFSET;
		rot.Apply(muzzlePos);
	    muzzlePos += pos;

		Vector3 shotDir = g_camera3D->GetForward();
		Quaternion shotRot;
		shotRot.SetRotation(Vector3::AxisZ, shotDir);

		//弾を生成、位置と速度
		Bullet* bullet = NewGO<Bullet>(0);
		bullet->pos = muzzlePos;
		bullet->moveSpeed = shotDir * BULLET_SPEED;
		//エフェクト
		EffectEmitter* muzzleFlash = NewGO<EffectEmitter>(0);
		muzzleFlash->Init(2);
		muzzleFlash->SetPosition(muzzlePos);
		muzzleFlash->SetRotation(shotRot);
		muzzleFlash->Play();

		//音
		SoundSource* shotsound = NewGO<SoundSource>(0);
		shotsound->Init(3);
		shotsound->Play(false);
		
		//次撃てるまでの時間をリセット
		coolTime = SHOT_INTERVAL;

		nowMagazine--;
		if (nowMagazine == 0)
		{
			nowreload = true;
			ReloadTime = RELOAD_TIME;
		}
	}

	
	
}

void  Pistol::Render(RenderContext &rc)
{
	modelRender.Draw(rc);
}