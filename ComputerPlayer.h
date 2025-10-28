#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class Board; // Forward declaration

class ComputerPlayer : public Player {
public:
    ComputerPlayer(char m = 'O');
    
    // Override getMove to implement AI logic
    int getMove() override;
    
    // AI helper methods
    int getBestMove(Board* board);
    int findWinningMove(Board* board, char mark);
    int findBlockingMove(Board* board);
    int getRandomEmptyCell(Board* board);
};

#endif
