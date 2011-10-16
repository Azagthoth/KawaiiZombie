/*
 * Zombie.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "KImage.h"

class Zombie : public KImage {
public:
	Zombie(Bitmap* image, Point* pos, String string);
	virtual ~Zombie();

	virtual void Update(int delta);
protected:
	bool hunt;
};

#endif /* ZOMBIE_H_ */
