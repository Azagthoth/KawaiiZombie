#include "GameView.h"
#include "World.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

GameView::GameView(void)
{
}

GameView::~GameView(void)
{
}

bool
GameView::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");

	return true;
}

result
GameView::OnInitializing(void)
{
	result r = E_SUCCESS;

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

	WorldManager::Instance()->Construct();
	WorldManager::Instance()->AddImage(new KImage(bitmapDecoder->DecodeN(L"/Home/Res/hero_test.png", BITMAP_PIXEL_FORMAT_ARGB8888), new Point(400, 240), new String(NURSE)));
	gameTimer = new GameTimer();
	return r;
}

result
GameView::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

result
GameView::OnDraw(void)
{
    Canvas *pCanvas = GetCanvasN();
    if(pCanvas)
    {
    	pCanvas->SetBackgroundColor(Color::COLOR_YELLOW);
    	pCanvas->Clear();

    	WorldManager::Instance()->Draw(pCanvas);
        delete pCanvas;

    	//AppLog("OnDraw success \n");
    }

    // do not call Show(), it will be called automatically after this callback function
    return E_SUCCESS;
}

void GameView::startTimer()
{
	gameTimer->construct(this, 5, true);
	gameTimer->start(20);
}

void GameView::update(int delta)
{
	//AppLog("Updating with delta : %d", delta);
	/*nursePosition->x += 5;
	if(nursePosition->x > 200)
	{
		nursePosition->x = 40;
	}*/
}
void GameView::draw(int delta)
{
	//AppLog("Drawing");
	Draw();
	Show();
}

void GameView::OnTouchPressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo & touchInfo)
{
	AppLog("OnTouchPressed is reached \n");
	Touch touch;
	// Set the Start info list to the current touch info list
	//pStartInfoList = touch.GetTouchInfoListN(source);
}

void GameView::OnTouchLongPressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void GameView::OnTouchReleased(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void GameView::OnTouchMoved(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
	AppLog("Moving nurse");
	KImage* nurse = WorldManager::Instance()->getImageByName(new String(NURSE));
	nurse->position->SetPosition(currentPosition);
}
void GameView::OnTouchDoublePressed(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void GameView::OnTouchFocusIn(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
void GameView::OnTouchFocusOut(const Osp::Ui::Control& source,const Osp::Graphics::Point& currentPosition,const Osp::Ui::TouchEventInfo& touchInfo)
{
}
