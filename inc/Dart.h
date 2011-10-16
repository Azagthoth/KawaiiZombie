/*
 * Dart.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef DART_H_
#define DART_H_

#include "KImagE.h"

class Dart : public KImage
{
public:
	Dart(Bitmap* image, Point* pos, String string, Point direction);
	virtual ~Dart();

	virtual void Update(int delta);
protected:
	Point movementOffset;
};

#endif /* DART_H_ */
