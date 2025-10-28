#include "ComputerPlayer.h"
#include "Board.h"
#include <cstdlib>
#include <ctime>

ComputerPlayer::ComputerPlayer(char m) : Player(m) {
    srand(time(0));
}

int ComputerPlayer::getMove() {
    // This is called by Game class which passes board
    return -1;
}

int ComputerPlayer::getBestMove(Board* board) {
    // AI Strategy:
    // 1. Try to win
    // 2. Block opponent from winning
    // 3. Take center if available
    // 4. Take a corner
    // 5. Take any remaining cell
    
    char opponentMark = (getMark() == 'X') ? 'O' : 'X';
    
    // Try to win
    int winMove = findWinningMove(board, getMark());
    if (winMove != -1) return winMove;
    
    // Block opponent
    int blockMove = findWinningMove(board, opponentMark);
    if (blockMove != -1) return blockMove;
    
    // Take center (index 4)
    if (board->isCellEmpty(4)) return 4;
    
    // Take a corner (0, 2, 6, 8)
    int corners[] = {0, 2, 6, 8};
    for (int i = 0; i < 4; i++) {
        if (board->isCellEmpty(corners[i])) {
            return corners[i];
        }
    }
    
    // Take any remaining cell
    return getRandomEmptyCell(board);
}

int ComputerPlayer::findWinningMove(Board* board, char mark) {
    // Try each empty cell to see if it results in a win
    for (int i = 0; i < 9; i++) {
        if (board->isCellEmpty(i)) {
            // Temporarily place mark
            board->setCellMark(i, mark);
            
            // Check if this is a winning move
            bool wins = board->checkWin(mark);
            
            // Undo the move
            board->setCellMark(i, ' ');
            
            if (wins) return i;
        }
    }
    return -1;
}

int ComputerPlayer::findBlockingMove(Board* board) {
    char opponentMark = (getMark() == 'X') ? 'O' : 'X';
    return findWinningMove(board, opponentMark);
}

int ComputerPlayer::getRandomEmptyCell(Board* board) {
    int emptyCells[9];
    int count = 0;
    
    for (int i = 0; i < 9; i++) {
        if (board->isCellEmpty(i)) {
            emptyCells[count++] = i;
        }
    }
    
    if (count > 0) {
        return emptyCells[rand() % count];
    }
    
    return -1;
}
