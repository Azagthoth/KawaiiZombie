/*
 * Nurse.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "Nurse.h"
#include "Constants.h"
#include "World.h"

#include "math.h"

Nurse::Nurse(Bitmap* image, Point* pos, String string) : KImage(image, pos, string) {
	movementOffset = null;
	life = NURSE_MAX_LIFE;
	// TODO Auto-generated constructor stub

	Image* bitmapDecoder = new Image();
	bitmapDecoder->Construct();

	WorldManager::Instance()->AddImage(new KImage(bitmapDecoder->DecodeN(L"/Res/480x800/jauge_3.png", BITMAP_PIXEL_FORMAT_ARGB8888), new Point(800-48, 48), LIFE));
	delete bitmapDecoder;

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

	if(life >= 0)
	{

		WorldManager::Instance()->DeleteImage(WorldManager::Instance()->GetImageByName(LIFE));

		String url;

		url.Format(256,L"/Res/480x800/jauge_%d.png",life);

		Image* bitmapDecoder = new Image();
		bitmapDecoder->Construct();

		WorldManager::Instance()->AddImage(new KImage(bitmapDecoder->DecodeN(url, BITMAP_PIXEL_FORMAT_ARGB8888), new Point(800-48, 48), LIFE));
		if(life == 0)
		{
			WorldManager::Instance()->AddImage(new KImage(bitmapDecoder->DecodeN(L"/Home/Res/lose.png", BITMAP_PIXEL_FORMAT_ARGB8888), new Point(400-128, 240- 128), LIFE));
		}
		delete bitmapDecoder;

	}
}
void Nurse::ResetLife()
{
	life = NURSE_MAX_LIFE;
}
