#include "GameObject.h"


GameObject::GameObject() {
	direction = gmtl::Vec3f();
}

GameObject::~GameObject() {
 
}

Pad1::Pad1() : GameObject() {
	direction.set(0,10,0);
	gmtl::Point3f paddlePoint1 = gmtl::Point3f(5, 100, 0);
	gmtl::Point3f paddlePoint2 = gmtl::Point3f(15, 140, 0);
	paddle = gmtl::AABoxf(paddlePoint1, paddlePoint2);
}

void Pad1::Update(float deltaTime)
{

}

void Pad1::Destroy()
{
}

int Pad1::getX()
{
	return paddle.getMin().mData[0];
}

int Pad1::getY()
{
	return paddle.getMin().mData[1];
}

int Pad1::getWidth()
{
	return paddle.getMax().mData[0] - getX();
}

int Pad1::getLength()
{
	return paddle.getMax().mData[1] - getY();
}

gmtl::AABoxf Pad1::getBox()
{
	return paddle;
}

Pad2::Pad2() : GameObject() {
	direction.set(0, 10, 0);
	gmtl::Point3f paddlePoint1 = gmtl::Point3f(385, 100, 0);
	gmtl::Point3f paddlePoint2 = gmtl::Point3f(395, 140, 0);
	paddle = gmtl::AABoxf(paddlePoint1, paddlePoint2);
}

void Pad2::Update(float deltaTime)
{
}

void Pad2::Destroy()
{
}

int Pad2::getX()
{
	return paddle.getMin().mData[0];
}

int Pad2::getY()
{
	return paddle.getMin().mData[1];
}

int Pad2::getWidth()
{
	return paddle.getMax().mData[0] - getX();
}

int Pad2::getLength()
{
	return paddle.getMax().mData[1] - getY();
}

gmtl::AABoxf Pad2::getBox()
{
	return paddle;
}

Ball::Ball() : GameObject()
{
	gmtl::Point3f centerPoint = gmtl::Point3f(160, 120, 0); //Set the point of the sphere at X, Y.
	ball.setCenter(centerPoint); //set Ball at given Point.
	ball.setRadius(radius); //set radius of sphere.
	direction.set(20, 0, 0); //set directions vector at X, Y. in this it it woudl be excatly pointing left!
}


/**
 * This function updates the ball
 * @param deltaTime the time to render one frame.
 */
void Ball::Update(float deltaTime)
{
	ball.mCenter += direction * deltaTime; //Add the vector scaled by the deltaTime to the centerPoint of the ball.
	if (getX() < 0)
	{
		ball.mCenter.mData[0] = 320;
	}
	else if (getX() > 400) {
		ball.mCenter.mData[0] = 10;
	}
}

void Ball::Destroy()
{
}

int Ball::getX(){return ball.mCenter.mData[0];}
int Ball::getY() {return ball.mCenter.mData[1];}
int Ball::getRadius(){return radius;}

void Ball::reverseDirection()
{   
	direction *= -1;
	//printf("direction: %.2f\n ball point: %.2f\n",direction.mData[0],ball.getCenter().mData[0]);
}

gmtl::Spheref Ball::getSphere()
{
	return ball;
}

Item::Item() : GameObject() {}


void Item::Update(float deltaTime)
{
}

void Item::Destroy()
{
}
