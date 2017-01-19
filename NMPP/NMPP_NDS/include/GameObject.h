#pragma once
#include <gmtl/gmtl.h>
enum Direction {neutral, up, down};
enum Mode {solo, host, client};

static struct Field {
	const int width = 256;
	const int height = 192;
	const int ballRadius = 4;
	const int ballSpeed = 150;
	const float maxBallAngle = 50;
	const int padSpeed = 150;
	const int padHeight = 32;
	const int padWidth = 8;
	const int pad1X = 5;
	const int pad2X = 243;
	const int padY = 80;
} playingField;

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
	 void setX(int x);
	 void setY(int y);
	 float getCenterY();
	 void setDirection(Direction dr);
	 gmtl::AABoxf getBox();

};

class Ball : public GameObject {	
private:
	int score1, score2;
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
	int getScore1();
	int getScore2();
	void setX(int x);
	void setY(int y);
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