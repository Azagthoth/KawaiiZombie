
#ifndef _FORMCREDITS_H_
#define _FORMCREDITS_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseController.h"


class FormCredits :
	public BaseController
{

// Construction
public:
	FormCredits(void);
	virtual ~FormCredits(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
