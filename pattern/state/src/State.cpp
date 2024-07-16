#include "State.hpp"
#include "MediaPlayer.hpp"

void LockedState::clickLock () {
	std::cout << "Going to the previous state from Locked state." << std::endl;
	if (player->isPlaying) 
		player->changeState (make_unique<PlayingState>(player));
	else 
		player->changeState (make_unique<ReadyState>(player));
}

void LockedState::clickPlay () {

}
void LockedState::clickNext () {

}
void LockedState::clickPrev () {

}



void ReadyState::clickLock () {
	std::cout << "Going to locked state" << std::endl;
	player->changeState (make_unique<LockedState>(player));
}
void ReadyState::clickPlay () {
	player->startPlayback();
    player->changeState(std::make_unique<PlayingState>(player));
}
void ReadyState::clickNext () {
	player->nextSong();
}

void ReadyState::clickPrev () {

}


void PlayingState::clickLock () {
	std::cout << "Going to Locked state." << std::endl;
	player->changeState (make_unique<LockedState>(player));
}
void PlayingState::clickPlay () {
	player->stopPlayback();
    player->changeState(std::make_unique<ReadyState>(player));
}
void PlayingState::clickNext () {
	// Assuming `event` and `doubleclick` are defined and checked elsewhere
    // if (event.doubleclick) {
    //     player->nextSong();
    // } else {
    //     player->fastForward(5);
    // }
	player->nextSong();
}
void PlayingState::clickPrev () {
	// Assuming `event` and `doubleclick` are defined and checked elsewhere
    // if (event.doubleclick) {
    //     player->previousSong();
    // } else {
    //     player->rewind(5);
    // }
    player->rewind(5);
} 