#pragma once

class GameObject {
public:
	gtml::Point location;
	GameObject();
	void Update(float deltaTime);
	void Destroy();
	~GameObject();
};

class Player : public GameObject {

};

class Ball : public GameObject {
	
};