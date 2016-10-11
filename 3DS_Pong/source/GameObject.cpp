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

Pad::Pad(bool playerOne) : GameObject() {
	direction = neutral;
	speed.set(0,playingField.padSpeed,0);
	gmtl::Point3f paddlePoint1;
	gmtl::Point3f paddlePoint2;
	if (playerOne)
	{
		paddlePoint1 = gmtl::Point3f(playingField.pad1X, playingField.padY, 0);
		paddlePoint2 = gmtl::Point3f(playingField.pad1X + playingField.padWidth, playingField.padY + playingField.padLength, 0);
	}
	else
	{
		paddlePoint1 = gmtl::Point3f(playingField.pad2X, playingField.padY, 0);
		paddlePoint2 = gmtl::Point3f(playingField.pad2X + playingField.padWidth, playingField.padY + playingField.padLength, 0);
	}
	paddle = gmtl::AABoxf(paddlePoint1, paddlePoint2);
}

void Pad::Update(float deltaTime)
{
	if (direction == up)
	{
		paddle.mMax -= speed * deltaTime;
		paddle.mMin -= speed * deltaTime;
		if (paddle.getMin().getData()[1] < 0)
		{   
			paddle.mMax[1] = getLength();
			paddle.mMin[1] = 0;			
		}
	}
	else if (direction == down)
	{
		paddle.mMax += speed * deltaTime;
		paddle.mMin += speed * deltaTime;
		if (paddle.getMax().getData()[1] > playingField.length)
		{
			paddle.mMin[1] = playingField.length - getLength();
			paddle.mMax[1] = playingField.length;
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



Ball::Ball() : GameObject()
{
	gmtl::Point3f centerPoint = gmtl::Point3f(playingField.width/2, playingField.length/2, 0); //Set the point of the sphere at X, Y.
	ball.setCenter(centerPoint); //set Ball at given Point.
	ball.setRadius(playingField.ballRadius); //set radius of sphere.
	speed.set(playingField.ballSpeed, 0, 0); //set directions vector at X, Y. in this it it would be excatly pointing left!
}


/**
 * This function updates the ball
 * @param deltaTime the time to render one frame.
 */
void Ball::Update(float deltaTime)
{
	ball.mCenter += speed * deltaTime; //Add the vector scaled by the deltaTime to the centerPoint of the ball.
	if (getX() < 0)
	{
		respawnBall();
		score.player2Score++;
	}
	else if (getX() > playingField.width) {
		respawnBall();
		score.player1Score++;
	}
	if (getY() < 0 || getY() > playingField.length)
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
	ball.mCenter = gmtl::Point3f(playingField.width / 2, playingField.length / 2, 0);
	speed *= -1;
}

Item::Item() : GameObject() {}


void Item::Update(float deltaTime)
{
}

void Item::Destroy()
{
}
