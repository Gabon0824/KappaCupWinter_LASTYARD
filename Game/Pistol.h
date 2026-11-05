#pragma once
class Player;
class Pistol : public IGameObject
{
public:
	Pistol();
	~Pistol();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	Player* player = nullptr;
	int handBoneId = -1;
};
