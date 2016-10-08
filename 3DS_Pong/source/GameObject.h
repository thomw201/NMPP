#pragma once
#include <gmtl/gmtl.h>

class GameObject {
protected:
	gmtl::Vec3f direction;
public:
	GameObject();
	virtual void Update(float deltaTime) = 0;
	virtual void Destroy() = 0;
	~GameObject();
};

class Pad1 : public GameObject {
private:
	gmtl::AABoxf paddle;
public:
	 Pad1();
	 void Update(float deltaTime) override;
	 void Destroy() override;
	 int getX();
	 int getY();
	 int getWidth();
	 int getLength();
	 gmtl::AABoxf getBox();

};

class Pad2 : public GameObject {
private:
	gmtl::AABoxf paddle;
public:
	Pad2();
	void Update(float deltaTime) override;
	void Destroy() override;
	int getX();
	int getY();
	int getWidth();
	int getLength();
	gmtl::AABoxf getBox();
};

class Ball : public GameObject {	
private:
	float radius = 10;
	gmtl::Spheref ball;
	gmtl::Matrix44f ballTranslation;
public:
	Ball();
	void Update(float deltaTime) override;
	void Destroy() override;
	int getX();
	int getY();
	int getRadius();
	void reverseDirection();
	gmtl::Spheref getSphere();
};

class Item : public GameObject {
public:
	Item();
	void Update(float deltaTime) override;
	void Destroy() override;
};