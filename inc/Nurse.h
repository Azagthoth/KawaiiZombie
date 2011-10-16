/*
 * Nurse.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef NURSE_H_
#define NURSE_H_

#include "KImage.h"

class Nurse : public KImage {
public:
	Nurse(Bitmap* image, Point* pos, String string);
	virtual ~Nurse();

	virtual void Update(int delta);
	void SetMovement(Point* movement);
	void SetTarget(Point target);
	void GetHit();
	void ResetLife();
protected:
	Point* movementOffset;
	Point target;
	int life;
};

#endif /* NURSE_H_ */
