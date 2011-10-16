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
using namespace Osp::Media;

class Sound {

	typedef enum{
		Sound1,
		Sound2
	} SoundId;

 class MyPlayerListener
    : public IPlayerEventListener
 {
    public:
    MyPlayerListener() {
    }
    void OnPlayerOpened(result r);
    void OnPlayerEndOfClip(void);
    void OnPlayerBuffering(int percent);
    void OnPlayerErrorOccurred(PlayerErrorReason r );
    void OnPlayerInterrupted();
    void OnPlayerReleased();
    void OnPlayerSeekCompleted(result r);
 };

 class CPlaySound:
	 public Osp::Base::Object,
	 public Osp::Base::Runtime::IRunnable
{
    public:
	 CPlaySound(Sound::SoundId sound=Sound1);
    ~CPlaySound(void);

    //void* Run(void);

    protected:
    Sound::SoundId _soundId;
 };

public:
	Sound();
	virtual ~Sound();
	result TestAudioPlaying(void);
	inline Player* GetPlayer(){ return _pPlayer;}
	result Play(SoundId id = Sound1);

protected:
	Player* _pPlayer;
	MyPlayerListener* _pListener;

};

typedef Singleton<Sound> SoundMgr;

#endif /* SOUND_H_ */
