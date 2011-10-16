/*
 * GameTimer.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: Fradow
 */

#include "GameTimer.h"
#include <FSystem.h>

#define TIMER_DEFAULT_TICK_MILLIS 20

//------------------------------------------------------------------------
GameTimer::GameTimer() : gameTimer(null)
{
}

//------------------------------------------------------------------------
GameTimer::~GameTimer()
{
    // stop and destroy timer if exist
    if (gameTimer != null)
    {
        gameTimer->Cancel();
        delete gameTimer;
        gameTimer = null;
    }
}

//------------------------------------------------------------------------
bool GameTimer::construct(GameView* gameRuntime)
{
    return construct(gameRuntime, TIMER_DEFAULT_TICK_MILLIS, false);
}

//------------------------------------------------------------------------
bool GameTimer::construct(GameView* gameRuntime, int timerTickDelay, bool repeatTicks)
{
    AppLog("Constructing timer: delay %i, repeat %s", timerTickDelay, repeatTicks ? "true" : "false");

    gameTimer = new Timer();
    game = gameRuntime;
    repeat = repeatTicks;
    delay = timerTickDelay;

    if(!gameTimer)
    {
        AppLog("Failed to create a timer.\n");
        return false;
    }

    if(IsFailed(gameTimer->Construct(*this)))
    {
        AppLog("Failed to construct the timer.\n");
        delete gameTimer;
        gameTimer = null;
        return false;
    }

return true;
}

//------------------------------------------------------------------------
void GameTimer::start(int millis)
{
    AppLog("Starting timer...");

    tickEnd = -1;
    gameTimer->Start(millis);
}

//------------------------------------------------------------------------
void GameTimer::stop()
{
    AppLog("Stopping timer...");

    gameTimer->Cancel();
}

//------------------------------------------------------------------------
void GameTimer::OnTimerExpired(Osp::Base::Runtime::Timer& timer)
{
    if(!gameTimer) return;

    result r = E_SUCCESS;
    // time before tick
    long long tickStart = -1;
    r = Osp::System::SystemTime::GetTicks(tickStart);

// run for the first time? If so tickEnd should be -1 and will be changed to zero delta
    if (tickEnd == -1) tickEnd = tickStart;

// call game
    int delta = (int) ((tickStart - tickEnd) & 0xFFFFFFFF);
    game->update(delta);
    game->draw(delta);
    //game->present();

// end of tick
    r = Osp::System::SystemTime::GetTicks(tickEnd);
    // next tick
    if (repeat)
    {
       int sleep = (int) (delay - (tickEnd - tickStart));
       if (sleep < 1) sleep = 1;
       gameTimer->Start(sleep);
    }
}
