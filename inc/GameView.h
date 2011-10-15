/*
 * GameView.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_
#include <FBase.h>
#include <FUi.h>
#include <FGrpCanvas.h>
#include <FMedia.h>
#include <FGraphics.h>
#include "GameTimer.h"
using namespace Osp::Graphics;
using namespace Osp::Media;

class GameTimer; //forward declaration

class GameView :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::ITouchEventListener,
	public Osp::Media::IPlayerEventListener
{

// Construction
public:
	GameView(void);
	virtual ~GameView(void);
	bool Initialize(void);

// Implementation
protected:
	Image* bitmapDecoder;
	GameTimer* gameTimer;

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

	virtual void OnPlayerBuffering (int percent);
	virtual void OnPlayerEndOfClip (void);
	virtual void OnPlayerErrorOccurred (PlayerErrorReason r);
	virtual void OnPlayerInterrupted (void);
	virtual void OnPlayerOpened (result r);
	virtual void OnPlayerReleased (void);
	virtual void OnPlayerSeekCompleted( result r );
};

#endif /* GAMEVIEW_H_ */
