
#ifndef _FORMHOME_H_
#define _FORMHOME_H_

#include <FBase.h>
#include <FUi.h>
#include <FMedia.h>
#include "BaseController.h"


class FormHome :
	public BaseController,
	public Osp::Media::IPlayerEventListener
{
		//Actions ids
		enum{
			ActionPlay=100,
			ActionScore,
			ActionHelp,
			ActionCredits
		};

// Construction
public:
	FormHome(void);
	virtual ~FormHome(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	//result PlaySound();

	 void OnPlayerOpened(result r)	;
	    void OnPlayerEndOfClip(void);
	    void OnPlayerBuffering(int percent);
	    void OnPlayerErrorOccurred(Osp::Media::PlayerErrorReason r );
	    void OnPlayerInterrupted();
	    void OnPlayerReleased();

// Implementation
protected:
	Osp::Ui::Controls::Button* _pPlayBtn;
	Osp::Ui::Controls::Button* _pScoreBtn;
	Osp::Ui::Controls::Button* _pHelpBtn;
	Osp::Ui::Controls::Button* _pCreditsBtn;
	Osp::Base::Runtime::Thread*	   _pSoundThread;

	Osp::Media::Player* _pPlayer;

// Generated call-back functions
public:
	void OnActionPerformed(const Control& source, int actionId);
};

#endif
