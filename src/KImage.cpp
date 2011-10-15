/*
 * KImage.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "KImage.h"

KImage::KImage(Bitmap* image, Point* pos, String* string)
{
	ressource = image;
	position = pos;
	name = string;
}

KImage::~KImage() {
	// TODO Auto-generated destructor stub
}
