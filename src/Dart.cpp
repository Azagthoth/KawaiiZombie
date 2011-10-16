/*
 * Dart.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "Dart.h"
#include "World.h"
#include "Constants.h"
#include "KImage.h"
#include "math.h"

Dart::Dart(Bitmap* image, Point* pos, String string, Point direction) : KImage(image, pos, string) {
	// TODO Auto-generated constructor stub
	movementOffset = direction;
	angle = 90;
	if(movementOffset.x != 0)
	{
		angle = tan(((float)movementOffset.y)/movementOffset.x) / M_PI * 180;
	}
	if(movementOffset.x > 0)
	{
		angle += 180;
	}
	angle = -angle;
	while(angle > 360)
	{
		angle -= 360;
	}
	while(angle < 0)
	{
		angle += 360;
	}
	//AppLog("angle : %f, movementOffset.x : %d, movementOffset.y : %d", angle, movementOffset.x, movementOffset.y);
}

Dart::~Dart() {
	// TODO Auto-generated destructor stub
}


void Dart::Update(int delta)
{
	float distance = sqrt(pow(movementOffset.x, 2) + pow(movementOffset.y, 2));
	position->SetPosition(Point(position->x + movementOffset.x / distance * delta * DART_SPEED,
								position->y + movementOffset.y / distance * delta * DART_SPEED));

}

float Dart::GetAngle()
{
	return angle;
}
