#include "stdafx.h"
#include "Map.h"
Map::Map()
{
	modelRender.Init("Assets/stage/yard/YardMap.tkm");
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

Map::~Map()
{

}

void Map::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
	modelRender.Draw(rc);
}
