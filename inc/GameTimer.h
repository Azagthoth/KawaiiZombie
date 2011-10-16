/*
 * GameTimer.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef GAMETIMER_H_
#define GAMETIMER_H_

#include "GameView.h"
using namespace Osp::Base::Runtime;

//code from http://ask.badadev.com/questions/4188/proper-main-loop
class GameView; //forward declaration

class GameTimer
: public ITimerEventListener
{
public:
	GameTimer();
	virtual ~GameTimer();
	bool construct(GameView* gameRuntime);
	bool construct(GameView* gameRuntime, int timerTickDelay, bool repeatTicks);
	void start(int millis);
	void stop();
	void OnTimerExpired(Osp::Base::Runtime::Timer& timer);
protected:
	Timer* gameTimer;
	GameView* game;
	bool repeat;
	int delay;
	long long tickEnd;
};

#endif /* GAMETIMER_H_ */
