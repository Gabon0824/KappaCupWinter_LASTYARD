#include "stdafx.h"
#include "Map.h"
Map::Map()
{
	modelRender.Init("Assets/stage/yard/YardMap.tkm");
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	btCollisionObject* mapCollision = physicsStaticObject.GetbtCollisionObject();

	//当たり判定だよ
	//mapCollision->setCollisionFlags(mapCollision->getCollisionFlags() | btCollisionObject::CF_DISABLE_VISUALIZE_OBJECT);
	//mapCollision->getCollisionFlags() | btCollisionObject::CF_DISABLE_VISUALIZE_OBJECT;
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

Map::~Map()
{

}

void Map::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}
