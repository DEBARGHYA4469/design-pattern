#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

#include "State.hpp"

using namespace std;

struct AudioPlayer{
	AudioPlayer () {
		state = make_unique <ReadyState> (this); // code in constructor is the last thing during initialization
	}
	void changeState (unique_ptr <State> state);
	
	// State Dependent functions 
	void clickLock ();
	void clickPlay ();
	void clickNext (); 
	void clickPrev ();

	void startPlayback (); 
	void stopPlayback ();
	void nextSong (); 
	void fastforward ();
	void rewind (int);

	bool isPlaying = false;
	unique_ptr <State> state; 
};

