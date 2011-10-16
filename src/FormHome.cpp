
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
}

FormHome::~FormHome(void)
{
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


