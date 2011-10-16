/*
 * Nurse.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "Nurse.h"
#include "Constants.h"
#include "World.h"
#include "Dart.h"

#include "math.h"

Nurse::Nurse(Bitmap* image, Point* pos, String string) : KImage(image, pos, string) {
	movementOffset = null;
	life = NURSE_MAX_LIFE;
	nextFire = DART_REFIRE_TIME;
	// TODO Auto-generated constructor stub

}

Nurse::~Nurse() {
	// TODO Auto-generated destructor stub
}

void Nurse::Update(int delta)
{
	if(movementOffset != null && life != 0)
	{
		float distance = sqrt(pow(movementOffset->x, 2) + pow(movementOffset->y, 2));
		Point afterMovement =
				Point(
				position->x + movementOffset->x / distance * delta * NURSE_SPEED,
				position->y + movementOffset->y / distance * delta * NURSE_SPEED);
		//TODO : check if in bounds / no collision
		position->SetPosition(afterMovement);

		nextFire -= delta;
		if(nextFire <= 0)
		{
			Image* bitmapDecoder = new Image();
			bitmapDecoder->Construct();
			AppLog("Creating dart");
			WorldManager::Instance()->AddImage(new Dart(bitmapDecoder->DecodeN(L"/Home/Res/seringue_test.png", BITMAP_PIXEL_FORMAT_ARGB8888), new Point(position->x + ressource->GetWidth()/2 - 96/2, position->y + ressource->GetHeight()/2 - 48/2), DART, Point(movementOffset->x, movementOffset->y)));
			nextFire = DART_REFIRE_TIME;
			delete bitmapDecoder;
		}
		if(sqrt(pow(position->x + ressource->GetWidth()/2 - target.x, 2) + pow(position->y + ressource->GetHeight()/2  - target.y, 2)) < 20)
		{
			movementOffset = null;
		}
	}
}

void Nurse::SetMovement(Point* movement)
{
	if(movementOffset != null)
	{
		delete movementOffset;
	}
	movementOffset = movement;
}


void Nurse::SetTarget(Point point)
{
	target = point;
}

void Nurse::GetHit()
{
	life--;
	if(life == 0)
	{
		Image* bitmapDecoder = new Image();
		bitmapDecoder->Construct();
		WorldManager::Instance()->AddImage(new KImage(bitmapDecoder->DecodeN(L"/Home/Res/lose.png", BITMAP_PIXEL_FORMAT_ARGB8888), new Point(400-128, 240-128), String("Loose")));
		delete bitmapDecoder;
	}
}
void Nurse::ResetLife()
{
	life = NURSE_MAX_LIFE;
}
