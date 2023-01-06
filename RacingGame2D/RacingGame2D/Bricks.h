#pragma once
#include"raylib.h"
class Bricks
{
public:

	Bricks(float widthP, float heightP, Vector2 posP);

	Vector2 getPos()const { return pos; }
	Vector2 getCenter() const { return center; }
	float getWidth() const { return width; }
	float getHeight() const { return height; }
	int getIsHere() const { return isHere; }
	Rectangle getCollisionBox() const { return collisionBox; }

	void setPos(const Vector2 posP);
	void setIsHere(const bool isHereP);


	void load();
	void update();
	void draw();

private:

	int isHere{ 1 };
	Rectangle collisionBox;
	Vector2 center;
	float width{ 80.0 };
	float height{ 20.0 };
	Vector2 pos;
};
