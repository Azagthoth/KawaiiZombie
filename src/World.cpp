/*
 * World.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "World.h"
#include "FBase.h"

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
	images->Add((Object&)*image);
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
	/*for(int i = 0; i < images->GetCount(); i++)
	{
		KImage* img = (KImage*)images->GetAt(i);
		target->DrawBitmap(*(img->position), *(img->ressource));
	}*/
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
	/*for(int i = 0; i < images->GetCount(); i++)
	{
		KImage* img = (KImage*)images->GetAt(i);
		img->Update(delta);
	}*/
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
			results->Add((Object&)img);
		}
	}

	delete pEnum;
	return results;
}
