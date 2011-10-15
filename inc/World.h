/*
 * World.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "KImage.h"

using namespace Osp::Base::Collection;

//TODO : singleton
class World {
public:
	World();
	virtual ~World();
	void AddImage(KImage* image);
	void MoveWorld(Point* offset);
	void Draw();
	KImage* getImageByName(String* name); //return first image with this name
	ArrayList* getImagesByNameN(String* name);
};

#endif /* WORLD_H_ */
