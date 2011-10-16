#include "Form1.h"
#include "GameTimer.h"
#include "Sound.h"
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

Form1::Form1(void)
{
}

Form1::~Form1(void)
{
}

bool
Form1::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");

	return true;
}

result
Form1::OnInitializing(void)
{
	result r = E_SUCCESS;

	_bSound = true;
	SoundMgr::Instance()->Play();

	// TODO: Add your initialization code here
	AddTouchEventListener(*this);
	//code from http://www.badadev.com/bada-tutorial-displaying-a-transparent-image-on-a-form/
	bitmapDecoder = new Image();

	// 3. Construct the decoder
	r= bitmapDecoder->Construct();
	if(IsFailed(r))
	{
		AppLog("Failed to construct decoder!");
	}

	// 4. decode the image with alphas (to allow transparency)
	bitmap = bitmapDecoder->DecodeN(L"/Home/Res/Nurse.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	if(!bitmap)
	{
		AppLog("Failed to decode image!");
	}


	gameTimer = new GameTimer();
	nursePosition = new Point(40, 40);
	return r;
}

result
Form1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

result
Form1::OnDraw(void)
{
    Canvas *pCanvas = GetCanvasN();
    if(pCanvas)
    {

    	pCanvas->SetBackgroundColor(Color::COLOR_YELLOW);
    	pCanvas->Clear();
    	pCanvas->SetForegroundColor(Color::COLOR_RED);
    	//pCanvas->DrawRectangle(Rectangle(50, 50, 100, 100));
    	pCanvas->DrawBitmap(*nursePosition,*bitmap);
        delete pCanvas;

    	AppLog("OnDraw success \n");
    }
    // do not call Show(), it will be called automatically after this callback function
    return E_SUCCESS;
}

void Form1::startTimer()
{
	gameTimer->construct(this, 5, true);
	gameTimer->start(20);
}

void Form1::update(int delta)
{
	AppLog("Updating with delta : %d", delta);
	nursePosition->x += 5;
	if(nursePosition->x > 200)
	{
		nursePosition->x = 40;
	}
}
void Form1::draw(int delta)
{
	Draw();
	Show();
}

void Form1::OnTouchPressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo & touchInfo)
{
	AppLog("OnTouchPressed is reached \n");
	Touch touch;
	// Set the Start info list to the current touch info list
	//pStartInfoList = touch.GetTouchInfoListN(source);
}

void Form1::OnTouchLongPressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void Form1::OnTouchReleased(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void Form1::OnTouchMoved(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void Form1::OnTouchDoublePressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void Form1::OnTouchFocusIn(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void Form1::OnTouchFocusOut(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}

void
Form1::OnActionPerformed(const Control& source, int actionId)
{
	// Interactions for video launching buttons
	switch (actionId)
	{
	case ActionSound:{
		_bSound = !_bSound;
		if(_bSound)
			SoundMgr::Instance()->GetPlayer()->Play();
		else SoundMgr::Instance()->GetPlayer()->Pause();
	}
	break;


	default:
		BaseController::OnActionPerformed(source, actionId);
		break;
	}
}




