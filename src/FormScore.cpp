
#include "FormScore.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


FormScore::FormScore(void)
{
}

FormScore::~FormScore(void)
{
}

bool
FormScore::Initialize()
{
	Form::Construct(L"IDF_FORM_SCORE");

	return true;
}

result
FormScore::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	return r;
}

result
FormScore::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


