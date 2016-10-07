#include "GameObject.h"


GameObject::GameObject() {
	direction = gmtl::Vec2f();
}

GameObject::~GameObject() {
 
}

Pad::Pad() : GameObject() {}

void Pad::Update(float deltaTime)
{

}

void Pad::Destroy()
{
}

Ball::Ball() : GameObject()
{
	gmtl::Point3f centerPoint = gmtl::Point3f(160, 120, 0); //Set the point of the sphere at X, Y.
	ball->setCenter(centerPoint); //set Ball at given Point.
	ball->setRadius(radius); //set radius of sphere.
	direction.set(1, 0); //set directions vector at X, Y;
	ballTranslation = gmtl::makeTrans< gmtl::Matrix44f >(direction);
}

void Ball::Update(float deltaTime)
{
	gmtl::Matrix44f translation = ballTranslation; //Copy currentBall translation matrix
	gmtl::setScale(translation, deltaTime); //Scale translation matrix with the deltaTime
	gmtl::xform(ball->mCenter, translation, ball->mCenter); //transform Sphere point with the translation Matrix
	if (getX() < 10)
	{
		ball->mCenter.mData[1] = 320;
	}
}

void Ball::Destroy()
{
}

int Ball::getX()
{
	return ball->mCenter.mData[0];
}

int Ball::getY()
{
	return ball->mCenter.mData[1];
}

Item::Item() : GameObject() {}


void Item::Update(float deltaTime)
{
}

void Item::Destroy()
{
}
