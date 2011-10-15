/*
 * Zombie.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "KImage.h"

class Zombie : KImage {
public:
	Zombie(Bitmap* image, Point* pos, String* string);
	virtual ~Zombie();
};

#endif /* ZOMBIE_H_ */
