/*
 * KImage.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef KIMAGE_H_
#define KIMAGE_H_

#include <FGrpCanvas.h>
#include <FMedia.h>
#include <FGraphics.h>
using namespace Osp::Graphics;
using namespace Osp::Media;
using namespace Osp::Base;

class KImage {
public:
	KImage(Bitmap* image, Point* pos, String string);
	virtual ~KImage();
	Bitmap* ressource;
	Point* position;
	String name;

	virtual void Update(int delta);
};

#endif /* KIMAGE_H_ */
