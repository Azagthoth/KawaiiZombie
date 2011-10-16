/*
 * World.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "World.h"
#include "FBase.h"

#include "Constants.h"
#include "Dart.h"
#include "Zombie.h"

#include <stdio.h>
#include <stdlib.h>

using namespace Osp::Base::Collection;

World::World() {
	nurse = null;
	nextZombieSpawn = ZOMBIE_SPAWN_TIME;
	// TODO Auto-generated constructor stub

}

World::~World() {
	// TODO Auto-generated destructor stub
}

result World::Construct()
{
	images = new ArrayList();
	images->Construct();
	imagesToAdd = new ArrayList();
	imagesToAdd->Construct();
	imagesToDelete = new ArrayList();
	imagesToDelete->Construct();
	viewPosition = new Point(1200, 720);
	return E_SUCCESS;
}
void World::AddImage(KImage* image)
{
	if(!imagesToAdd->Contains(*image))
	{
		imagesToAdd->Add(*image);
	}
}

void World::DeleteImage(KImage* image)
{
	if(!imagesToDelete->Contains(*image))
	{
		imagesToDelete->Add(*image);
	}
}

void World::SetNurse(Nurse* image)
{
	nurse = image;
	AddImage(image);
}
Nurse* World::GetNurse()
{
	return nurse;
}

void World::MoveView(Point* offset)
{
	viewPosition->SetPosition(viewPosition->x + offset->x, viewPosition->y + offset->y);
}
void World::Draw(Canvas* target)
{
	IEnumerator* pEnum = images->GetEnumeratorN();
	KImage* img = null;
	while (pEnum->MoveNext() == E_SUCCESS)
	{
		img = (KImage*)(pEnum->GetCurrent());
		if(img->name.Equals(DART, true))
		{
			Dart* dart = (Dart*)img;
			target->DrawBitmap(*(img->position), *(img->ressource), Point(dart->ressource->GetWidth()/2, dart->ressource->GetHeight()/2), (int)dart->GetAngle());
		}
		else
		{
			target->DrawBitmap(*(img->position), *(img->ressource));
		}
	}

	delete pEnum;
}
void World::Update(int delta)
{
	IEnumerator* pEnum = images->GetEnumeratorN();
	KImage* img = null;
	while (pEnum->MoveNext() == E_SUCCESS)
	{
		img = (KImage*)pEnum->GetCurrent();
		img->Update(delta);
	}

	delete pEnum;

	pEnum = images->GetEnumeratorN();
	ArrayList* toDelete = new ArrayList();
	toDelete->Construct();
	while (pEnum->MoveNext() == E_SUCCESS)
	{
		img = (KImage*)pEnum->GetCurrent();
		img->Update(delta);
		if(img->name.Equals(DART, true))
		{
			if(img->position->x > 800 || img->position->x + img->ressource->GetWidth() < 0
				|| img->position->y > 480 || img->position->y + img->ressource->GetHeight() < 0)
			{
				toDelete->Add((Object&)*img);
			}
		}
	}
	images->RemoveItems(*toDelete, true);
	delete toDelete;
	delete pEnum;

	nextZombieSpawn -= delta;
	if(nextZombieSpawn < 0)
	{
		Point* spawnPosition;
		int border = rand()%4;
		AppLog("Border (rand) : %d", border);
		switch(border)
		{
		case 0:
			spawnPosition = new Point(20, 20);
			break;
		case 1:
			spawnPosition = new Point(800 - 20 - 128, 20);
			break;
		case 2:
			spawnPosition = new Point(20, 480 - 20 - 128);
			break;
		case 3:
			spawnPosition = new Point(800 - 20 - 128, 480 - 20 - 128);
			break;
		}
		Image* bitmapDecoder = new Image();
		bitmapDecoder->Construct();
		WorldManager::Instance()->AddImage(new Zombie(bitmapDecoder->DecodeN(L"/Home/Res/zombie_test.png", BITMAP_PIXEL_FORMAT_ARGB8888), spawnPosition, ZOMBIE));
		delete bitmapDecoder;
		nextZombieSpawn = ZOMBIE_SPAWN_TIME;
	}

	time += delta;
	if(time > 200)
	{
		time = 0;
		DeleteImage(GetImageByName(ZOMBIE_DEAD));
	}
	images->AddItems(*imagesToAdd);
	imagesToAdd->RemoveAll(false);

	images->RemoveItems(*imagesToDelete, false);
	imagesToDelete->RemoveAll(true);
	//TODO : check darts to delete out of bounds ones
}
KImage* World::GetImageByName(String name)
{
	KImage* target = null;
	IEnumerator* pEnum = images->GetEnumeratorN();
	KImage* img = null;
	while (pEnum->MoveNext() == E_SUCCESS && target == null)
	{
		img = (KImage*)pEnum->GetCurrent();
		if(img->name.Equals(name, true))
		{
			target = img;
		}
	}

	delete pEnum;
	return target;
}
ArrayList* World::GetImagesByNameN(String name)
{
	ArrayList* results = new ArrayList();
	IEnumerator* pEnum = images->GetEnumeratorN();
	KImage* img = null;
	while (pEnum->MoveNext() == E_SUCCESS)
	{
		img = (KImage*)pEnum->GetCurrent();
		if(img->name.Equals(name, true))
		{
			results->Add(*img);
		}
	}

	delete pEnum;
	return results;
}
