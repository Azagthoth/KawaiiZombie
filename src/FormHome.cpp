
#include "FormHome.h"
#include "Constants.h"
#include "GameView.h"
#include "FormScore.h"
#include "FormHelp.h"
#include "FormCredits.h"
#include "Sound.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Base::Runtime;

FormHome::FormHome(void)
{
	// Buttons
	_pPlayBtn = null;
	_pScoreBtn = null;
	_pHelpBtn = null;
	_pCreditsBtn = null;
	_pSoundThread = null;
}

FormHome::~FormHome(void)
{
	SAFE_DELETE(_pSoundThread);
}

bool
FormHome::Initialize()
{
	result r = Form::Construct(L"IDF_FORM_HOME");
	if (IsFailed(r))
		return false;
	SetOrientation(ORIENTATION_LANDSCAPE );
	return true;
}

result
FormHome::OnInitializing(void)
{
	result r = E_SUCCESS;
	// Buttons settings
	_pPlayBtn 	= static_cast<Button*>(GetControl(K_BUTTON_PLAY));
	_pScoreBtn	= static_cast<Button*>(GetControl(K_BUTTON_SCORE));
	_pHelpBtn	= static_cast<Button*>(GetControl(K_BUTTON_HELP));
	_pCreditsBtn= static_cast<Button*>(GetControl(K_BUTTON_CREDITS));

	_pPlayBtn->SetActionId(ActionPlay);
	_pPlayBtn->AddActionEventListener(*this);
//	_pScoreBtn->SetActionId(ActionScore);
//	_pScoreBtn->AddActionEventListener(*this);
//	_pHelpBtn->SetActionId(ActionHelp);
//	_pHelpBtn->AddActionEventListener(*this);
//	_pCreditsBtn->SetActionId(ActionCredits);
//	_pCreditsBtn->AddActionEventListener(*this);

	_pScoreBtn->SetEnabled(false);
	_pHelpBtn->SetEnabled(false);
	_pCreditsBtn->SetEnabled(false);

	// Sound
//	Sound::CPlaySound* runSound = new Sound::CPlaySound;
//	_pSoundThread = new Thread;
//	_pSoundThread->Construct(*runSound);
//	_pSoundThread->Start();
//	SoundMgr::Instance()->SetSoundMode(true);
//	SoundMgr::Instance()->Play();
	SoundMgr::Instance()->TestAudioPlaying();

	return r;
}

result
FormHome::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


void
FormHome::OnActionPerformed(const Control& source, int actionId)
{
	// Interactions for video launching buttons
	switch (actionId)
	{
	case ActionPlay:{
		GameView* pGameForm = new GameView;
		if (!pGameForm) break;
		if (!pGameForm->Initialize())
			break;
		//Stop sound
//		_pSoundThread->Stop();
//		_pSoundThread->Exit();

		PushForm(pGameForm);
		pGameForm->startTimer();
	}
	break;

//	case ActionScore:{
//		FormScore* pScoreForm = new FormScore;
//		if (!pScoreForm) break;
//		if (!pScoreForm->Initialize())
//			break;
//		PushForm(pScoreForm);
//	}
//	break;
//
//	case ActionHelp:{
//		FormHelp* pHelpForm = new FormHelp;
//		if (!pHelpForm) break;
//		if (!pHelpForm->Initialize())
//			break;
//		PushForm(pHelpForm);
//	}
//	break;
//
//	case ActionCredits:{
//		FormCredits* pCreditsForm = new FormCredits;
//		if (!pCreditsForm) break;
//		if (!pCreditsForm->Initialize())
//			break;
//		PushForm(pCreditsForm);
//	}
//	break;

	default:
		BaseController::OnActionPerformed(source, actionId);
		break;
	}
}
//
//result FormHome::PlaySound(){
//	//SoundMgr::Instance()->TestAudioPlaying();
//	Osp::Base::String path0("/Res/Sounds/KawaiiZombies_speedcoremix.mp3");
//	result r = E_SUCCESS;
//		if(!_pPlayer){
//
//			_pPlayer = new Player();
//
//			// Create audio player
//			r = _pPlayer->Construct(*this, null);
//			if (IsFailed(r)) goto CATCH;
//		}
//
//		// Open file asynchronously
//		r = _pPlayer->OpenFile(path0);
//		if (IsFailed(r)) goto CATCH;
//
//		r = _pPlayer->SetLooping(true);
//		if (IsFailed(r)) goto CATCH;
//
//		r = _pPlayer->SetVolume(100);
//		if (IsFailed(r)) goto CATCH;
//
//		r = _pPlayer->Play();
//
//		return r;
//
//		AppLogDebug(" <<<<< Result from audio player : %s ", GetErrorMessage(r));
//
//		CATCH:{
//		SAFE_DELETE(_pPlayer);
//		}
//
//
//}



void
FormHome::OnPlayerOpened(result r)
{
	return;
}


void
FormHome::OnPlayerEndOfClip(void)
{

}

void
FormHome::OnPlayerBuffering(int percent)
{
}
void
FormHome::OnPlayerErrorOccurred(PlayerErrorReason r)
{
}

void
FormHome::OnPlayerInterrupted( void )
{
}

void
FormHome::OnPlayerReleased( void )
{
	return;
}
