#pragma once
class Map : public IGameObject
{
public:
	Map();
	~Map();

	void Render(RenderContext& rc);

	//モデルレンダー
	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

