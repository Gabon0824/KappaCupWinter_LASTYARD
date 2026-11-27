#pragma once
class Player;
class  GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();

	Player* m_player;
	Vector3 toCameraPos;
	float nowshift = 22.0f;
	float nowDistance = 65.0f;
	float nowViewAngle = 60.0f;

};

