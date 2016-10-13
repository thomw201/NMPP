#pragma once
#include <gmtl/gmtl.h>
enum Direction {neutral, up, down};

static struct Field {
	const int width = 400;
	const int height = 240;
	const int ballRadius = 5;
	const int ballSpeed = 90;
	const float maxBallAngle = 50;
	const int padSpeed = 120;
	const int padHeight = 40;
	const int padWidth = 10;
	const int pad1X = 5;
	const int pad2X = 385;
	const int padY = 100;
} playingField;

static struct Score {
	int player1Score = 0;
	int player2Score = 0;
} score;

class GameObject {
protected:
	gmtl::Vec3f speed;
public:
	GameObject();
	virtual void Update(float deltaTime) = 0;
	virtual void Destroy() = 0;
	~GameObject();
};

class Pad : public GameObject {
private:
	gmtl::AABoxf paddle;
	Direction direction;
public:
	 Pad();
	 Pad(bool playerOne);
	 void Update(float deltaTime) override;
	 void Destroy() override;
	 int getX();
	 int getY();
	 int getWidth();
	 int getLength();
	 float getCenterY();
	 void setDirection(Direction dr);
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
	void reverseDirection(float anglePercentage);
	gmtl::Spheref getSphere();
	void respawnBall();
};

class Item : public GameObject {
public:
	Item();
	void Update(float deltaTime) override;
	void Destroy() override;
};