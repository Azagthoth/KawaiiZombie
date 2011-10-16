/*
 * BaseController.h
 *
 *
 */

#ifndef BASECONTROLLER_H_
#define BASECONTROLLER_H_

#include <FBase.h>
#include <FUi.h>
#include <FNet.h>



typedef enum
{
	AlertTypeInformation = 0,
	AlertTypeWarning = 1,
	AlertTypeError = 2
} AlertType;



class BaseController:
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
	public Osp::Ui::IOrientationEventListener,
	public Osp::Ui::IWindowEventListener
{
public:
	static Osp::Ui::Controls::Form& GetCurrent();

public:
	BaseController();
	virtual ~BaseController();

	bool operator==(const BaseController &form);
	bool operator!=(const BaseController &form);
	const BaseController& operator=(const BaseController &form);

	virtual void OnOrientationChanged(const Osp::Ui::Control&, Osp::Ui::OrientationStatus) {};
	virtual void OnActionPerformed(const Osp::Ui::Control& control, int action);

	/*
	 * Called whenever system is low memory.
	 * Subclasses must first attempt to clean up their specific resources
	 * before calling superclass implementation.
	 */
	virtual void OnLowMemory() {};

	void Display();

	bool IsCurrent();

/*--------------------------------------------------------------------------*/
/*--- Form lifecycle -------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
public:
	virtual bool Initialize() { return true; };
	virtual result OnInitializing();
	virtual result OnTerminating() { return E_SUCCESS; };
	void ResetAll();

protected:
	/*
	 * Called whenever this form has just been shown.
	 * Should be overwritten by subclasses in order to perform tasks at this point of lifecycle.
	 */
	virtual void DidAppear();

	/*
	 * Called whenever this form has just been hidden.
	 * Should be overwritten by subclasses in order to perform tasks at this point of lifecycle.
	 */
	virtual void DidDisappear();

	/*
	 * Called whenever this form is about to be shown.
	 * Should be overwritten by subclasses in order to perform tasks at this point of lifecycle.
	 */
	virtual void WillAppear();

	/*
	 * Called whenever this form is about to be hidden.
	 * Should be overwritten by subclasses in order to perform tasks at this point of lifecycle.
	 */
	virtual void WillDisappear();

/*--------------------------------------------------------------------------*/
/*--- Navigation support ---------------------------------------------------*/
/*--------------------------------------------------------------------------*/
public:
	typedef Osp::Base::Collection::StackT<BaseController *> Navigation;

	/*
	 * Checks whether this form is navigation capable or not.
 	 */
	bool HasNavigation() const;

	/*
	 * Resets the user navigation to this form or to the first navigation form
	 * if this form is not part of navigation.
	 */
	BaseController *ResetNavigation(BaseController *upTo=null);

	/*
	 * Moves to next form.
	 * When no history is true, current form won't be kept in navigation.
	 */
	void PushForm(BaseController* form, bool noHistory=false);

	/*
	 * Moves to previous form.
 	 */
	void PopForm();

protected:
	/*
	 * Gets the user navigation this form is part of.
	 * If no navigation is defined, it is created on the fly.
	 */
	Navigation &GetNavigation();

	/*
	 * Sets the user navigation this controller is part of.
	 */
	void SetNavigation(Navigation &navigation);

	/*
	 * The user navigation this controller is part of.
	 */
	Navigation* _navigation;





/*--------------------------------------------------------------------------*/
/*--- Wait indicator support ----------------------------------------------*/
/*--------------------------------------------------------------------------*/
protected:

	/*
	 * Displays the wait indicator.
	 * Does nothing if wait indicator is already displayed.
	 */
	void ShowWaitIndicator();

	/*
	 * Hides the wait indicator.
	 * Does nothing if wait indicator is already hidden.
	 */
	void HideWaitIndicator();

public:
	void OnWindowActivated(const Osp::Ui::Window &source);
	void OnWindowClosed(const Osp::Ui::Window &source);
	void OnWindowDeactivated(const Osp::Ui::Window &source);
	void OnWindowOpened(const Osp::Ui::Window &source);

private:

	/*
	 * The global wait modal popup.
	 */
	static Osp::Ui::Controls::Popup *__waitPopup;

/*--------------------------------------------------------------------------*/
/*--- Popup message support ------------------------------------------------*/
/*--------------------------------------------------------------------------*/
public:
	/*
	 * Display message modal popup.
	 */
	void Alert(const Osp::Base::String& message, AlertType type=AlertTypeInformation);

	/*
	 * Display a confirmation message modal popup.
	 */
	bool Confirm(const Osp::Base::String& message,
				 AlertType type=AlertTypeInformation);

private:
	const Osp::Base::String AlertTypeToString(AlertType type);

private:

	typedef enum
	{
		ActionBack = 99
	} Action;
};


// Type alias for navigation
//
typedef Osp::Base::Collection::StackT<BaseController *> Navigation;

#endif /* BASECONTROLLER_H_ */
