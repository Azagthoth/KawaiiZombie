
#ifndef _FORMHOME_H_
#define _FORMHOME_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseController.h"


class FormHome :
	public BaseController
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

// Implementation
protected:
	Osp::Ui::Controls::Button* _pPlayBtn;
	Osp::Ui::Controls::Button* _pScoreBtn;
	Osp::Ui::Controls::Button* _pHelpBtn;
	Osp::Ui::Controls::Button* _pCreditsBtn;

// Generated call-back functions
public:
	void OnActionPerformed(const Control& source, int actionId);
};

#endif
