/*
 * World.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "World.h"
#include "FBase.h"

#include "Constants.h"

using namespace Osp::Base::Collection;

World::World() {
	nurse = null;
	// TODO Auto-generated constructor stub

}

World::~World() {
	// TODO Auto-generated destructor stub
}

result World::Construct()
{
	images = new ArrayList();
	images->Construct();
	viewPosition = new Point(1200, 720);
	return E_SUCCESS;
}
void World::AddImage(KImage* image)
{
	images->Add(*image);
}

void World::DeleteImage(KImage* image)
{
	images->Remove((Object&)*image,true);
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
		target->DrawBitmap(*(img->position), *(img->ressource));
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
