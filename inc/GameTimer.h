/*
 * GameTimer.h
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#ifndef GAMETIMER_H_
#define GAMETIMER_H_

#include "Form1.h"
using namespace Osp::Base::Runtime;

//code from http://ask.badadev.com/questions/4188/proper-main-loop
class Form1; //forward declaration

class GameTimer
: public ITimerEventListener
{
public:
	GameTimer();
	virtual ~GameTimer();
	bool construct(Form1* gameRuntime);
	bool construct(Form1* gameRuntime, int timerTickDelay, bool repeatTicks);
	void start(int millis);
	void stop();
	void OnTimerExpired(Osp::Base::Runtime::Timer& timer);
protected:
	Timer* gameTimer;
	Form1* game;
	bool repeat;
	int delay;
	long long tickEnd;
};

#endif /* GAMETIMER_H_ */
