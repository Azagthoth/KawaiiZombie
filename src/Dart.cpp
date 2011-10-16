/*
 * Dart.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "Dart.h"
#include "World.h"
#include "Zombie.h"
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
	ArrayList* zombies = WorldManager::Instance()->GetImagesByNameN(ZOMBIE);
	IEnumerator* pEnum = zombies->GetEnumeratorN();
	Zombie* zombie = null;
	bool found = false;
	while (pEnum->MoveNext() == E_SUCCESS && !found)
	{
		zombie = (Zombie*)pEnum->GetCurrent();
		Point offset = Point(position->x + ressource->GetWidth()/2 - zombie->position->x - zombie->ressource->GetWidth()/2, position->y + ressource->GetHeight()/2 - zombie->position->y - zombie->ressource->GetHeight()/2);
		float distance = sqrt(pow(offset.x, 2) + pow(offset.y, 2));
		if(distance < 50)
		{
			Image* bitmapDecoder = new Image();
			bitmapDecoder->Construct();
			WorldManager::Instance()->AddImage(new KImage(bitmapDecoder->DecodeN(L"/Home/Res/zombie_dead.png", BITMAP_PIXEL_FORMAT_ARGB8888), new Point(*(zombie->position)), ZOMBIE_DEAD));
			WorldManager::Instance()->DeleteImage(zombie);
			WorldManager::Instance()->DeleteImage(this);
			delete bitmapDecoder;
			found = true;
		}
	}

	delete pEnum;
	delete zombies;

}

float Dart::GetAngle()
{
	return angle;
}
