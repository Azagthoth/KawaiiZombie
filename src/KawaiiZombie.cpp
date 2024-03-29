/**
 * Name        : KawaiiZombie
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "KawaiiZombie.h"
#include "FormHome.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

KawaiiZombie::KawaiiZombie()
{
}

KawaiiZombie::~KawaiiZombie()
{
}

Application*
KawaiiZombie::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new KawaiiZombie();
}

bool
KawaiiZombie::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:
	// Initialize UI resources and application specific data.
	// The application's permanent data and context can be obtained from the appRegistry.
	//
	// If this method is successful, return true; otherwise, return false.
	// If this method returns false, the application will be terminated.

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	// Create a form

	FormHome *pFormHome = new FormHome();
	pFormHome->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pFormHome);

	// Set the current form
	pFrame->SetCurrentForm(*pFormHome);

	// Draw and Show the form
	pFormHome->Draw();
	pFormHome->Show();

	//pFormHome->PlaySound();

	return true;
}

bool
KawaiiZombie::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
	return true;
}

void
KawaiiZombie::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
KawaiiZombie::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
KawaiiZombie::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
KawaiiZombie::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
KawaiiZombie::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
KawaiiZombie::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
