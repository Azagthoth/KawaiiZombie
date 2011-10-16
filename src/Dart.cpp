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
