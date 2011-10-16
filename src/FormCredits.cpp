
#include "FormCredits.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


FormCredits::FormCredits(void)
{
}

FormCredits::~FormCredits(void)
{
}

bool
FormCredits::Initialize()
{
	Form::Construct(L"IDF_FORM_CREDITS");

	return true;
}

result
FormCredits::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	return r;
}

result
FormCredits::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


