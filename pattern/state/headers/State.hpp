#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

struct AudioPlayer;

struct State
{	
	State (AudioPlayer* player) : player (player) {}
	virtual ~State () = default;

	virtual void clickLock () = 0;
	virtual void clickPlay () = 0;
	virtual void clickNext () = 0;
	virtual void clickPrev () = 0;

	AudioPlayer* player;
};

struct LockedState : State {
	LockedState (AudioPlayer* player) : State (player) {} 
	virtual void clickLock () override;
	virtual void clickPlay () override;
	virtual void clickNext () override;
	virtual void clickPrev () override;
};

struct ReadyState : State {
	ReadyState (AudioPlayer* player) : State (player) {} 
	virtual void clickLock () override;
	virtual void clickPlay () override;
	virtual void clickNext () override;
	virtual void clickPrev () override;
};

struct PlayingState : State {
	PlayingState (AudioPlayer* player) : State (player) {} 
	virtual void clickLock () override;
	virtual void clickPlay () override;
	virtual void clickNext () override;
	virtual void clickPrev () override;
};