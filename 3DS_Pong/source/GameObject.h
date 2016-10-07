#pragma once
#include <gmtl\gmtl.h>

class GameObject {
protected:
	gmtl::Vec2f direction;
public:
	GameObject();
	virtual void Update(float deltaTime) = 0;
	virtual void Destroy() = 0;
	~GameObject();
};

class Pad : public GameObject {
private:
	gmtl::AABoxf *paddle;
public:
	 Pad();
	 void Update(float deltaTime) override;
	 void Destroy() override;

};

class Ball : public GameObject {	
private:
	float radius = 20;
	gmtl::Spheref *ball;
	gmtl::Matrix44f ballTranslation;
public:
	Ball();
	void Update(float deltaTime) override;
	void Destroy() override;
	int getX();
	int getY();
};

class Item : public GameObject {
public:
	Item();
	void Update(float deltaTime) override;
	void Destroy() override;
};