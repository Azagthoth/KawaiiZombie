
#ifndef _FORMSCORE_H_
#define _FORMSCORE_H_

#include <FBase.h>
#include <FUi.h>
#include "BaseController.h"


class FormScore :
	public BaseController
{

// Construction
public:
	FormScore(void);
	virtual ~FormScore(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
