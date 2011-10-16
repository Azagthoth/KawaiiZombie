/*
 * Sound.cpp
 *
 *  Created on: 16/10/2011
 *      Author: Lionel
 */

#include "Sound.h"
#include "Constants.h"

using namespace Osp::Base;

Osp::Base::String path0("/Res/Sounds/KawaiiZombies_speedcoremix.mp3");


Sound::Sound() {
	_pPlayer = null;
	_pListener = null;
}

Sound::~Sound() {
	if (_pPlayer) _pPlayer->Stop();
	SAFE_DELETE(_pPlayer);
	SAFE_DELETE(_pListener);
}

// The player's listener should be implemented to control asynchronously.
void Sound::MyPlayerListener::OnPlayerOpened(result r)
{
	//This listener is used when OpenXXX() is set to work asynchronously.
	//Insert your code to operate after the resource is opened.
	result rt = E_SUCCESS;
	rt = SoundMgr::Instance()->GetPlayer()->Play();

	if (IsFailed(rt))
	{
		//Need to handle the exception.
	}
}


void Sound::MyPlayerListener::OnPlayerEndOfClip(void)
{
	//Insert your code to operate after the player reaches end of clip.
	result r = E_SUCCESS;
	r = SoundMgr::Instance()->GetPlayer()->Play();
	if (IsFailed(r))
	{
		//Handle the exception.
	}
}

void Sound::MyPlayerListener::OnPlayerBuffering(int percent)
{
	//Insert your code to operate while the buffering for a remote resource is going on.
}

void Sound::MyPlayerListener::OnPlayerErrorOccurred(PlayerErrorReason r )
{
	//Insert your code to operate after any error occurred.
}

void Sound::MyPlayerListener::OnPlayerInterrupted()
{
	//Insert your code here
}

void Sound::MyPlayerListener::OnPlayerReleased()
{
	//Insert your code here
}

void Sound::MyPlayerListener::OnPlayerSeekCompleted(result r)
{
	//Insert your code here
}

result Sound::TestAudioPlaying(void)
{
	result r = E_SUCCESS;
	if(!_pPlayer){

		_pPlayer = new Player();
		_pListener = new MyPlayerListener;

		// Create audio player
		r = _pPlayer->Construct(*_pListener, 0);
		if (IsFailed(r)) goto CATCH;
	}

	// Open file asynchronously
	r = _pPlayer->OpenFile(path0, true);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->SetLooping(true);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->SetVolume(80);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->Play();

	AppLogDebug(" <<<<< Result from audio player : %s ", GetErrorMessage(r));

	CATCH:
	SAFE_DELETE(_pPlayer);
	SAFE_DELETE(_pListener);

	return r;
}

result Sound::Play(SoundId id){
	result r = E_SUCCESS;
	String path;
	if(!_pPlayer){

		_pPlayer = new Player();
		_pListener = new MyPlayerListener;

		// Create audio player
		r = _pPlayer->Construct(*_pListener, 0);
		if (IsFailed(r)) goto CATCH;
	}

	switch(id){
	case Sound1:
		path = path0;
		break;
	case Sound2:
		break;
	default:
		path = path0;
	}
	// Open file asynchronously
	r = _pPlayer->OpenFile(path, true);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->SetLooping(true);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->SetVolume(10);
	if (IsFailed(r)) goto CATCH;

	CATCH:
	SAFE_DELETE(_pPlayer);
	SAFE_DELETE(_pListener);

	return r;
}

Sound::CPlaySound::CPlaySound(Sound::SoundId sound) {
	// Constructor
	_soundId = sound;
}
Sound::CPlaySound::~CPlaySound(void) {
	// Destructor
	}

void*	Sound::CPlaySound::Run(void) {

}

