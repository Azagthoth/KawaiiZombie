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

using namespace Osp::Base::Collection;

//TODO : singleton
class World {
public:
	World();
	virtual ~World();
	result Construct();
	void AddImage(KImage* image);
	void MoveView(Point* offset);
	void Draw(Canvas* target);
	void Update(int delta);
	KImage* getImageByName(String* name); //return first image with this name
	ArrayList* getImagesByNameN(String* name);

protected:
	Point* viewPosition;
	ArrayList* images;
};


typedef Singleton<World> WorldManager;

#endif /* WORLD_H_ */
