/*
 * Sound.h
 *
 *  Created on: 16/10/2011
 *      Author: Lionel
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <FBase.h>
#include <FMedia.h>
#include <FGraphics.h>
#include <FUi.h>
#include "Singleton.h"

#define PLAYER_COUNT	11

class Sound {

	typedef enum{
		SoundMain,
		SoundCureEmAll,
		SoundHelp,
		SoundKawaiiZombies,
		SoundKoala,
		SoundOurs,
		SoundPanda,
		SoundPigeon,
		SoundSouris,
		SoundTouch,
		SoundZombiesCrush,
		TotalNbSounds
	} SoundId;
public:
 class MyPlayerListener
    : public Osp::Media::IPlayerEventListener
 {
    public:
    MyPlayerListener() {
    }
    void OnPlayerOpened(result r);
    void OnPlayerEndOfClip(void);
    void OnPlayerBuffering(int percent);
    void OnPlayerErrorOccurred(Osp::Media::PlayerErrorReason r );
    void OnPlayerInterrupted();
    void OnPlayerReleased();
    void OnPlayerSeekCompleted(result r);
 };

 class CPlaySound:
	 public Osp::Base::Object,
	 public Osp::Base::Runtime::IRunnable
{
    public:
	 CPlaySound(Sound::SoundId sound=SoundMain);
    ~CPlaySound(void);

    Osp::Base::Object * Run();

    protected:
    Sound::SoundId _soundId;
 };

public:
	Sound();
	virtual ~Sound();
	result TestAudioPlaying(void);
	//inline Osp::Media::Player* GetPlayer(){ return _pPlayer;}
	result Play(SoundId id = SoundMain);
	void CleanUp(void);
	void SetSoundMode(bool );

protected:
	Osp::Media::Player* _pPlayer;
	Osp::Media::Player *__pPlayer[PLAYER_COUNT];
	MyPlayerListener* _pListener;
	int __volume[PLAYER_COUNT];
	bool __paused;
	bool __opened;
	bool __modeOn;
	bool __isPaused[PLAYER_COUNT];
	Osp::Base::String __filename[PLAYER_COUNT];

	void AudioPlayerClose(Osp::Media::Player* pPlayer);
	void AudioPlayerPlay(Osp::Media::Player* pPlayer, int i);
	void AudioPlayerStop(Osp::Media::Player* pPlayer);
	void AudioPlayerPause(Osp::Media::Player* pPlayer);
	void AudioPlayerOpen();
	void ReleaseAllPlayer();
};

typedef Singleton<Sound> SoundMgr;

#endif /* SOUND_H_ */
