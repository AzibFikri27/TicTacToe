#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(char m = 'X');
    
    // Override getMove to get input from mouse click
    int getMove() override;
};

#endif
