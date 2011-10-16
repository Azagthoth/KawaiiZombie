/*
 * BaseController.cpp
 *
 */

#include <FApp.h>
#include <FGraphics.h>

#include "BaseController.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Graphics;
using namespace Osp::Net::Http;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

Form&
BaseController::GetCurrent()
{
	return *Application::GetInstance()->GetAppFrame()->GetFrame()->GetCurrentForm();
}

BaseController::BaseController()
{
	_navigation = null;
}

BaseController::~BaseController()
{

}

bool BaseController::operator==(const BaseController &form)
{
	return false;
}

bool BaseController::operator!=(const BaseController &form)
{
	return true; //!(this == form);
}

const BaseController& BaseController::operator=(const BaseController &form)
{
	return *this;
}

result BaseController::OnInitializing()
{
	// Initalizing background
	//
	//SetBackgroundColor(Style::BACKGROUND_COLOR);



	AddOrientationEventListener(*this);
	return E_SUCCESS;
}




/*--------------------------------------------------------------------------*/
/*--- Navigation support ---------------------------------------------------*/
/*--------------------------------------------------------------------------*/

Navigation&
BaseController::GetNavigation()
{
	if (!_navigation)
	{
		_navigation = new Navigation;
		_navigation->Construct();
		_navigation->Push(this);
	}
	return *_navigation;
}


void
BaseController::SetNavigation(Navigation& navigation)
{
	if (_navigation != &navigation)
	{
		if (_navigation && (_navigation->GetCount() == 1))
			delete _navigation;
		_navigation = &navigation;
	}
}

bool
BaseController::HasNavigation() const
{
	return (_navigation != null);
}

void
BaseController::PushForm(BaseController* next, bool noHistory)
{
	Navigation &navigation = GetNavigation();
	navigation.Push(next);
	next->SetNavigation(navigation);

	// Setting back softkey accordingly.
	//
	if (next->HasSoftkey(SOFTKEY_1))
	{
		next->SetSoftkeyActionId(SOFTKEY_1, ActionBack);
		next->SetSoftkeyEnabled(SOFTKEY_1, true);
		next->AddSoftkeyActionListener(SOFTKEY_1, *next);
		if (next->GetSoftkeyText(SOFTKEY_1).IsEmpty() && this->HasTitle() && (this->GetTitleText() != null))
			next->SetSoftkeyText(SOFTKEY_1, this->GetTitleText());
	}

	next->Display();
}

void
BaseController::PopForm()
{
	if (this->HasNavigation())
	{
		Navigation& navigation = GetNavigation();
		if (navigation.GetCount() > 1)
		{
			BaseController *current = null;
			navigation.Pop(current);

			BaseController *previous;
			navigation.Peek(previous);
			previous->Display();

			Application::GetInstance()->GetAppFrame()->GetFrame()->RemoveControl(*current);
			current = null;
		}
	}
}

void
BaseController::ResetAll()
{

}

BaseController *
BaseController::ResetNavigation(BaseController *upTo)
{
	if (HasNavigation())
	{
		Navigation &navigation = GetNavigation();
		BaseController *current = null;
		navigation.Peek(current);
		while ((navigation.GetCount() > 1) && (upTo != current))
		{
			navigation.Pop(current);
			BaseController *previous = current;
			navigation.Peek(current);
			Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*current);
			Application::GetInstance()->GetAppFrame()->GetFrame()->RemoveControl(*previous);
		}
		return current;
	}
	return this;
}

void
BaseController::OnActionPerformed(const Control& control, int action)
{
	if (action == ActionBack)
		this->PopForm();
}

/*--------------------------------------------------------------------------*/
/*--- Life cycle -----------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

void
BaseController::WillAppear() {}

void
BaseController::WillDisappear() {}

void
BaseController::DidAppear() {}

void
BaseController::DidDisappear() {}

bool
BaseController::IsCurrent()
{
	return (&GetCurrent() == this);
}

void
BaseController::Display()
{
	Frame *frame = Application::GetInstance()->GetAppFrame()->GetFrame();
	BaseController *currentForm = dynamic_cast<BaseController *>(frame->GetCurrentForm());

	if (currentForm && (this != currentForm))
		currentForm->WillDisappear();

	if (frame->GetControls()->Contains(*this))
		frame->SetCurrentForm(*this);
	else
		frame->AddControl(*this); // Puts this at top most form.

	if (this != currentForm)
		this->WillAppear();

//	if (!GetWaitPopup()->GetShowState())
//	{
		Draw();
		Show();
//	}
	if (this != currentForm)
		this->DidAppear();
	if (currentForm)
		currentForm->DidDisappear();
}

/*--------------------------------------------------------------------------*/
/*--- Wait indicator support ----------------------------------------------*/
/*--------------------------------------------------------------------------*/
Popup *BaseController::__waitPopup = null;

void
BaseController::ShowWaitIndicator()
{
	if (!__waitPopup)
	{
		__waitPopup = new Popup();
		__waitPopup->Construct(L"IDP_POPUP_WAIT");
	//	__waitPopup->AddWindowEventListener(*this);
		__waitPopup->Show();
	}
}

void
BaseController::HideWaitIndicator()
{
	if (__waitPopup)
	{
		__waitPopup->SetShowState(false);
		Form &current = GetCurrent();
		current.Draw();
		current.Show();
		delete __waitPopup;
		__waitPopup = null;
	}
}

//void
//BaseController::OnWindowActivated(const Window &source)
//{
//	if (&source == __waitPopup)
//	{
//		Flash *waitAnimation = static_cast<Flash *>(__waitPopup->GetControl("IDC_FLASH_WAIT_ANIMATION"));
//		waitAnimation->Play();
//	}
//}
//
//void
//BaseController::OnWindowClosed(const Window &source)
//{
//}
//
//void
//BaseController::OnWindowDeactivated(const Window &source)
//{
//	if (&source == __waitPopup)
//	{
//		Flash *waitAnimation = static_cast<Flash *>(__waitPopup->GetControl("IDC_FLASH_WAIT_ANIMATION"));
//		waitAnimation->Stop();
//	}
//}
//
//void
//BaseController::OnWindowOpened(const Window &source)
//{
//}

/*--------------------------------------------------------------------------*/
/*--- Popup message support ------------------------------------------------*/
/*--------------------------------------------------------------------------*/
void
BaseController::Alert(const String& message, AlertType type)
{
	MessageBox messageBox;
	messageBox.Construct(AlertTypeToString(type), message, MSGBOX_STYLE_OK);
	int result = 0;
	messageBox.ShowAndWait(result);
}

bool
BaseController::Confirm(const String& message, AlertType type)
{
	MessageBox messageBox;
	messageBox.Construct(AlertTypeToString(type), message, MSGBOX_STYLE_YESNO);
	int result = 0;
	messageBox.ShowAndWait(result);
	return (result == MSGBOX_RESULT_YES);
}


const String
BaseController::AlertTypeToString(AlertType type)
{
	switch (type)
	{
		case AlertTypeInformation:
		{
			return L"Information";
		}
		case AlertTypeWarning:
		{
			return L"Avertissement";
		}
		case AlertTypeError:
		{
			return L"Erreur";
		}
		default:break;
	}
}



