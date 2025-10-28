#include "HumanPlayer.h"
#include <graphics.h>

HumanPlayer::HumanPlayer(char m) : Player(m) {}

int HumanPlayer::getMove() {
    // Wait for mouse click and return cell index (0-8)
    // This will be called by the Game class which will handle the actual logic
    // Returns -1 to indicate human input is needed
    return -1;
}
