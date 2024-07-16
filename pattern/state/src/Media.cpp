#include "State.hpp"
#include "MediaPlayer.hpp"

void AudioPlayer::changeState (unique_ptr <State> state){
	this->state = std::move (state); 
}

void AudioPlayer::clickLock (){ state->clickLock(); }
void AudioPlayer::clickPlay (){ state->clickPlay(); }
void AudioPlayer::clickNext (){ state->clickNext(); }
void AudioPlayer::clickPrev (){ state->clickPrev(); }

void AudioPlayer::startPlayback (){ std::cout << "Start playback" << std::endl; isPlaying = true; }
void AudioPlayer::stopPlayback (){ std::cout << "Start playback" << std::endl; isPlaying = false; }
void AudioPlayer::nextSong (){ std::cout << "Next song" << std::endl; }
void AudioPlayer::fastforward (){ std::cout << "Next song" << std::endl; }
void AudioPlayer::rewind(int time) {
    std::cout << "Rewind " << time << " seconds" << std::endl;
}