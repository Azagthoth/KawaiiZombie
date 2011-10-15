#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FUi.h>
#include <FGrpCanvas.h>
#include <FMedia.h>
#include <FGraphics.h>
#include "GameTimer.h"
using namespace Osp::Graphics;
using namespace Osp::Media;

class GameTimer; //forward declaration

class Form1 :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::ITouchEventListener
{

// Construction
public:
	Form1(void);
	virtual ~Form1(void);
	bool Initialize(void);

// Implementation
protected:
	Bitmap* bitmap;
	Image* bitmapDecoder;
	GameTimer* gameTimer;
	Point* nursePosition;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual result OnDraw(void);

	void startTimer();
	void update(int delta);
	void draw(int delta);

	virtual void OnTouchPressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo & touchInfo);
	virtual void OnTouchMoved (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchDoublePressed (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
};

#endif	//_FORM1_H_
