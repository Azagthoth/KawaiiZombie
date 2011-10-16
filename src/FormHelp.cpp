
#include "FormHelp.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


FormHelp::FormHelp(void)
{
}

FormHelp::~FormHelp(void)
{
}

bool
FormHelp::Initialize()
{
	Form::Construct(L"IDF_FORM_HELP");

	return true;
}

result
FormHelp::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	return r;
}

result
FormHelp::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


