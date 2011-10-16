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


class Sound {

	typedef enum{
		Sound1,
		Sound2
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
	 CPlaySound(Sound::SoundId sound=Sound1);
    ~CPlaySound(void);

    Osp::Base::Object * Run();

    protected:
    Sound::SoundId _soundId;
 };

public:
	Sound();
	virtual ~Sound();
	result TestAudioPlaying(void);
	inline Osp::Media::Player* GetPlayer(){ return _pPlayer;}
	result Play(SoundId id = Sound1);

protected:
	Osp::Media::Player* _pPlayer;
	MyPlayerListener* _pListener;

};

typedef Singleton<Sound> SoundMgr;

#endif /* SOUND_H_ */
