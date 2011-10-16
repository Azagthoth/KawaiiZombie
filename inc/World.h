/*
 * World.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "KImage.h"
#include "Singleton.h"
#include "Nurse.h"

using namespace Osp::Base::Collection;

//TODO : singleton
class World {
public:
	World();
	virtual ~World();
	result Construct();
	void AddImage(KImage* image);
	void DeleteImage(KImage* image);
	void SetNurse(Nurse* image);
	Nurse* GetNurse();
	void MoveView(Point* offset);
	void Draw(Canvas* target);
	void Update(int delta);
	KImage* GetImageByName(String name); //return first image with this name
	ArrayList* GetImagesByNameN(String name);
protected:
	Point* viewPosition;
	ArrayList* images;
	ArrayList* imagesToAdd;
	ArrayList* imagesToDelete;
	Nurse* nurse;

	int nextZombieSpawn;
	int time;
};


typedef Singleton<World> WorldManager;

#endif /* WORLD_H_ */
