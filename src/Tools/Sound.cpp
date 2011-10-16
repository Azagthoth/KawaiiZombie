/*
 * Sound.cpp
 *
 *  Created on: 16/10/2011
 *      Author: Lionel
 */

#include "Sound.h"
#include "Constants.h"

using namespace Osp::Base;
using namespace Osp::Media;

Osp::Base::String path0("/Res/Sounds/KawaiiZombies_speedcoremix.mp3");


Sound::Sound() {
	 result r=E_SUCCESS;

	_pPlayer = null;
	_pListener = null;

	for (int i=0; i<TotalNbSounds; i++) {
		__pPlayer[i] = null;
		__volume[i] = 50;
		__isPaused[i] = true;
	}
	__paused = true;
	__opened = false;
	__modeOn = false;

	__filename[0] = "/Res/Sounds/KawaiiZombies_speedcoremix.mp3";
	__filename[1] = "/Res/Sounds/cure_em_all.mp3";
	__filename[2] = "/Res/Sounds/help_me.mp3";
	__filename[3] = "/Res/Sounds/kawaiizombiiies.mp3";
	__filename[4] = "/Res/Sounds/koala.mp3";
	__filename[5] = "/Res/Sounds/ours.mp3";
	__filename[6] = "/Res/Sounds/panda.mp3";
	__filename[7] = "/Res/Sounds/pigeon.mp3";
	__filename[8] = "/Res/Sounds/souris.mp3";
	__filename[9] = "/Res/Sounds/touch.mp3";
	__filename[10] = "/Res/Sounds/zombies_crush1.mp3";

	_pListener = new MyPlayerListener;

	// init players
//	for (int i=0; i<PLAYER_COUNT; i++) {
//
//		__pPlayer[i] = new Player();
//		TRY_CATCH(__pPlayer[i], r = GetLastResult(), "new Player failed: %s", GetErrorMessage(GetLastResult()));
//		r = __pPlayer[i]->Construct(*_pListener, null);
//		TRY_CATCH(r == E_SUCCESS, , "Player.Construct failed: %s", GetErrorMessage(r));
//	}
	//AudioPlayerOpen();
//	CATCH:
//	AppLog("Player.Construct failed");
}

Sound::~Sound() {
	if (_pPlayer) _pPlayer->Stop();
	ReleaseAllPlayer();
	SAFE_DELETE(_pPlayer);
	SAFE_DELETE(_pListener);
}

void
Sound::ReleaseAllPlayer()
{
	for (int i=0; i<PLAYER_COUNT; i++) {
		if( __pPlayer[i] )
		{
			PlayerState state = __pPlayer[i]->GetState();
			if( state == PLAYER_STATE_PLAYING || state == PLAYER_STATE_PAUSED )
			{
				__pPlayer[i]->Stop();
				__pPlayer[i]->Close();
			}else if(state == PLAYER_STATE_OPENED || state == PLAYER_STATE_ENDOFCLIP || state == PLAYER_STATE_STOPPED )
			{
				__pPlayer[i]->Close();
			}
			delete __pPlayer[i];
			__pPlayer[i] = null;
		}
	}
}

void
Sound::AudioPlayerOpen()
{
	result r = E_SUCCESS;
	if (!__opened)
	{
		for (int i=0; i<PLAYER_COUNT; i++) {
			r = __pPlayer[i]->OpenFile(__filename[i]); // Sync Open
			TRY_CATCH(r == E_SUCCESS, , "Player.OpenFile(%S) failed:% s", __filename[i].GetPointer(), GetErrorMessage(r));

			// Set Volume for proper mixing
			__pPlayer[i]->SetVolume(50);
		}
		__opened = true;
	}else{
		// just Playback
	}

CATCH:
	return;
}


// The player's listener should be implemented to control asynchronously.
void Sound::MyPlayerListener::OnPlayerOpened(result r)
{
	//This listener is used when OpenXXX() is set to work asynchronously.
	//Insert your code to operate after the resource is opened.
//	result rt = E_SUCCESS;
//	rt = SoundMgr::Instance()->GetPlayer()->Play();
//
//	if (IsFailed(rt))
//	{
//		//Need to handle the exception.
//	}
}


void Sound::MyPlayerListener::OnPlayerEndOfClip(void)
{
	//Insert your code to operate after the player reaches end of clip.
//	result r = E_SUCCESS;
//	r = SoundMgr::Instance()->GetPlayer()->Play();
//	if (IsFailed(r))
//	{
//		//Handle the exception.
//	}
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
	r = _pPlayer->OpenFile(path0);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->SetLooping(true);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->SetVolume(100);
	if (IsFailed(r)) goto CATCH;

	r = _pPlayer->Play();

	return r;

	CATCH:{
		SAFE_DELETE(_pPlayer);
		SAFE_DELETE(_pListener);
		return E_FAILURE;
	}
}

result Sound::Play(SoundId id){
	AudioPlayerPlay(__pPlayer[id], id);
}

Sound::CPlaySound::CPlaySound(Sound::SoundId sound) {
	// Constructor
	_soundId = sound;
}
Sound::CPlaySound::~CPlaySound(void) {
	// Destructor
	}
Object*	Sound::CPlaySound::Run(void) {
	SoundMgr::Instance()->Play(_soundId);
}

void Sound::CleanUp(void)
{
	for (int i=0; i<PLAYER_COUNT; i++) {
		if (__pPlayer[i]) {
			PlayerState state = __pPlayer[i]->GetState();
			if( state == PLAYER_STATE_PLAYING || state == PLAYER_STATE_PAUSED)
			{
				__pPlayer[i]->Stop();
			}
			__pPlayer[i]->SetLooping(false);
			AudioPlayerClose(__pPlayer[i]);
		}
	}
}

void
Sound::AudioPlayerClose(Osp::Media::Player* pPlayer)
{
	pPlayer->Close();
}

void
Sound::AudioPlayerPlay(Osp::Media::Player* pPlayer, int i)
{
	if (__paused){
		result r = E_SUCCESS;
		if (!pPlayer){
			pPlayer = new Player();
			//TRY_CATCH(pPlayer, r = GetLastResult(), "new Player failed: %s", GetErrorMessage(GetLastResult()));
			r = pPlayer->Construct(*_pListener, null);
			//TRY_CATCH(r == E_SUCCESS, , "Player.Construct failed: %s", GetErrorMessage(r));
			r = pPlayer->OpenFile(__filename[i]); // Sync Open
			//TRY_CATCH(r == E_SUCCESS, , "Player.OpenFile(%S) failed:% s", __filename[i].GetPointer(), GetErrorMessage(r));

			// Set Volume for proper mixing
			pPlayer->SetVolume(50);
		}

		PlayerState state = pPlayer->GetState();

		// Re-Play the playing.
		if( state == PLAYER_STATE_ENDOFCLIP || state == PLAYER_STATE_OPENED
				|| state == PLAYER_STATE_INITIALIZED || state == PLAYER_STATE_STOPPED
				|| state == PLAYER_STATE_PAUSED)
		{
			r = pPlayer->Play();
			TRY_CATCH(r == E_SUCCESS, ,"Player.Play failed:%s %d", GetErrorMessage(r), state);
			__paused = false;
			for (int i=0; i<PLAYER_COUNT; i++) {
				if (pPlayer == __pPlayer[i]) {
					__isPaused[i] = false;
				}
			}
		}
		CATCH:
		return;
	}
}

void
Sound::AudioPlayerPause(Osp::Media::Player* pPlayer)
{
	result r = E_SUCCESS;
	// Pause the playing.
	if( pPlayer->GetState() == PLAYER_STATE_PLAYING )
	{
		r = pPlayer->Pause();
		if(IsFailed(r))
		{
			AppLog(">>>>>> (AudioPlayer::AudioPlayerPlay) Pause has failed: %s\n", GetErrorMessage(r));
			return;
		}
		__paused = true;
		for (int i=0; i<PLAYER_COUNT; i++) {
			if (pPlayer == __pPlayer[i]) {
				__isPaused[i] = true;
			}
		}
	}
}

void
Sound::AudioPlayerStop(Osp::Media::Player* pPlayer)
{
	PlayerState state = pPlayer->GetState();

	// Stop the playing.
	if(state == PLAYER_STATE_PLAYING || state == PLAYER_STATE_PAUSED)
	{
		int i;
		for (i=0; i<PLAYER_COUNT; i++) {
			if (pPlayer == __pPlayer[i])
				break;
		}
		TRY_CATCH(i < PLAYER_COUNT, , "Invalid Player:%d", i);

		if (pPlayer->IsLooping())
		{
			pPlayer->SetLooping(false);
		}
		pPlayer->Stop();
		__isPaused[i] = false;
	}

CATCH:
	return;
}

void Sound::SetSoundMode(bool open){

	__modeOn = !open;
	if (!__modeOn){
		for (int i=0; i<TotalNbSounds; i++){
			AudioPlayerPause(__pPlayer[i]);
		}
	}
}
