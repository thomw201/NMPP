#include "GameObject.h"


GameObject::GameObject() {
	speed = gmtl::Vec3f();
}

GameObject::~GameObject() {
 
}

Pad::Pad()
{
	Pad(true);
}

/**
*Constructor for the Pad object.
*@param playerone is a bool that decides which paddle to make. 
*/
Pad::Pad(bool playerOne) : GameObject() {
	direction = neutral;
	speed.set(0,playingField.padSpeed,0);
	gmtl::Point3f paddlePoint1;
	gmtl::Point3f paddlePoint2;
	if (playerOne)
	{
		paddlePoint1 = gmtl::Point3f(playingField.pad1X, playingField.padY, 0);
		paddlePoint2 = gmtl::Point3f(playingField.pad1X + playingField.padWidth, playingField.padY + playingField.padHeight, 0);
	}
	else
	{
		paddlePoint1 = gmtl::Point3f(playingField.pad2X, playingField.padY, 0);
		paddlePoint2 = gmtl::Point3f(playingField.pad2X + playingField.padWidth, playingField.padY + playingField.padHeight, 0);
	}
	paddle = gmtl::AABoxf(paddlePoint1, paddlePoint2);
}

/**
* This function updates The Paddle object.
* @param deltaTime the time is the time difference between each Update call.
*/
void Pad::Update(float deltaTime)
{
	if (direction == up)
	{
		paddle.mMax -= speed * deltaTime;
		paddle.mMin -= speed * deltaTime;
		if (paddle.getMin().getData()[1] < 0)
		{   
			paddle.mMax[1] = playingField.padHeight;
			paddle.mMin[1] = 0;			
		}
	}
	else if (direction == down)
	{
		paddle.mMax += speed * deltaTime;
		paddle.mMin += speed * deltaTime;
		if (paddle.getMax().getData()[1] > playingField.height)
		{
			paddle.mMin[1] = playingField.height - playingField.padHeight;
			paddle.mMax[1] = playingField.height;
		}
	}
}

void Pad::Destroy()
{
}

int Pad::getX()
{
	return paddle.getMin().mData[0];
}

int Pad::getY()
{
	return paddle.getMin().mData[1];
}

int Pad::getWidth()
{
	return paddle.getMax().mData[0] - getX();
}

int Pad::getLength()
{
	return paddle.getMax().mData[1] - getY();
}

void Pad::setX(int x)
{
	paddle.mMax[0] = x + playingField.padWidth;
	paddle.mMin[0] = x;
}

void Pad::setY(int y)
{
	paddle.mMax[1] = y + playingField.padHeight;
	paddle.mMin[1] = y;
}

float Pad::getCenterY()
{
	return paddle.getMin()[1] + getLength()/2;
}

void Pad::setDirection(Direction dr)
{
	direction = dr;
}

gmtl::AABoxf Pad::getBox()
{
	return paddle;
}


/**
*Constructor for the ball object!
*/
Ball::Ball() : GameObject()
{
	gmtl::Point3f centerPoint = gmtl::Point3f(playingField.width/2, playingField.height/2, 0); //Set the point of the sphere at X, Y.
	ball.setCenter(centerPoint); //set Ball at given Point.
	ball.setRadius(playingField.ballRadius); //set radius of sphere.
	speed.set(playingField.ballSpeed, 0, 0); //set directions vector at X, Y. in this it it would be excatly pointing left!
	score1 = 0;
	score2 = 0;
}


/**
* This function updates The Ball object.
* @param deltaTime the time is the time difference between each Update call.
*/
void Ball::Update(float deltaTime)
{
	ball.mCenter += speed * deltaTime; //Add the vector scaled by the deltaTime to the centerPoint of the ball.
	if (getX() < 0)
	{
		respawnBall();
		score2++;
	}
	else if (getX() > playingField.width) {
		respawnBall();
		score1++;
	}
	if (getY() < 0 || getY() > playingField.height)
	{
		speed.mData[1] *= -1;
	}
}

void Ball::Destroy()
{
}

int Ball::getX(){return ball.mCenter.mData[0];}
int Ball::getY() {return ball.mCenter.mData[1];}
int Ball::getRadius(){return radius;}

int Ball::getScore1()
{
	return score1;
}

int Ball::getScore2()
{
	return score2;
}

void Ball::setX(int x)
{
	ball.mCenter[0] = x;
}

void Ball::setY(int y)
{
	ball.mCenter[1] = y;
}

void Ball::setScore1(int score)
{
	score1 = score;
}

void Ball::setScore2(int score)
{
	score2 = score;
}

void Ball::reverseDirection(float anglePercentage)
{   
	//Ball angle goes from 100 to -100
	speed.mData[0] *= -1;
	speed.mData[1] = gmtl::Math::aTan(playingField.maxBallAngle) / 100 * anglePercentage * playingField.ballSpeed; //gmtl::Math::aTan(playingField.maxBallAngle / 100 * anglePercentage) * playingField.ballSpeed;	
}

gmtl::Spheref Ball::getSphere()
{
	return ball;
}

void Ball::respawnBall()
{
	ball.mCenter = gmtl::Point3f(playingField.width / 2, playingField.height / 2, 0);
	speed *= -1;
}

Item::Item() : GameObject() {}


void Item::Update(float deltaTime)
{
}

void Item::Destroy()
{
}
