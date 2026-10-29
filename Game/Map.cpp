#include "stdafx.h"
#include "Map.h"
Map::Map()
{
	modelRender.Init("Assets/stage/DemoMap.tkm");
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

Map::~Map()
{

}

void Map::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}
