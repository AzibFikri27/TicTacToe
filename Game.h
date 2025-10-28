#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

enum GameMode {
    MENU,
    SINGLE_PLAYER,
    MULTIPLAYER,
    GAME_OVER
};

class Game {
private:
    Board* board;           // Aggregation: Game uses Board but doesn't own it exclusively
    Player* player1;        // Aggregation: Players can exist independently
    Player* player2;
    Player* currentPlayer;
    GameMode mode;
    bool gameRunning;
    char winner;
    int screenWidth;
    int screenHeight;

public:
    Game(int width = 800, int height = 600);
    ~Game();
    
    // Getters
    GameMode getMode() const;
    bool isGameRunning() const;
    char getWinner() const;
    Player* getCurrentPlayer() const;
    
    // Setters
    void setMode(GameMode m);
    void setGameRunning(bool running);
    void setWinner(char w);
    
    // Methods
    void initialize();
    void showMenu();
    void setupPlayers(GameMode selectedMode);
    void run();
    void handleInput();
    void update();
    void render();
    void switchPlayer();
    void checkGameStatus();
    void displayResult();
    void cleanup();
    bool askPlayAgain();
    void displayMessage(const char* message, int y);
};

#endif
