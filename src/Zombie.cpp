/*
 * Zombie.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "Zombie.h"
#include "World.h"
#include "Nurse.h"
#include "Constants.h"
#include "math.h"

Zombie::Zombie(Bitmap* image, Point* pos, String string) : KImage(image, pos, string) {
	hunt = true;

}

Zombie::~Zombie() {
	// TODO Auto-generated destructor stub
}

void Zombie::Update(int delta)
{
	if(hunt)
	{
		Nurse* brain = WorldManager::Instance()->GetNurse();
		Point offset = Point(position->x + ressource->GetWidth()/2 - brain->position->x - brain->ressource->GetWidth()/2, position->y + ressource->GetHeight()/2 - brain->position->y - brain->ressource->GetHeight()/2);
		float distance = sqrt(pow(offset.x, 2) + pow(offset.y, 2));
		if(distance > 50)
		{
			position->SetPosition(position->x - offset.x / distance * delta * ZOMBIE_SPEED,
								  position->y - offset.y / distance * delta * ZOMBIE_SPEED);
		}
		else
		{
			hunt = false;
			WorldManager::Instance()->GetNurse()->GetHit();
			//TODO : loose
		}
	}
}
