
#ifndef _FORMHELP_H_
#define _FORMHELP_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseController.h"


class FormHelp :
	public BaseController
{

// Construction
public:
	FormHelp(void);
	virtual ~FormHelp(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
