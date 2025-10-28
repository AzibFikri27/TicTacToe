#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <graphics.h>
#include <cstring>
#include <cstdio>

Game::Game(int width, int height) 
    : board(nullptr), player1(nullptr), player2(nullptr), 
      currentPlayer(nullptr), mode(MENU), gameRunning(true), 
      winner(' '), screenWidth(width), screenHeight(height) {}

Game::~Game() {
    cleanup();
}

GameMode Game::getMode() const {
    return mode;
}

bool Game::isGameRunning() const {
    return gameRunning;
}

char Game::getWinner() const {
    return winner;
}

Player* Game::getCurrentPlayer() const {
    return currentPlayer;
}

void Game::setMode(GameMode m) {
    mode = m;
}

void Game::setGameRunning(bool running) {
    gameRunning = running;
}

void Game::setWinner(char w) {
    winner = w;
}

void Game::initialize() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    // Create board
    board = new Board(150, 225, 150);
}

void Game::showMenu() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
    
    // Title
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(screenWidth/2 - 150, 100, "TIC-TAC-TOE");
    
    // Instructions
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(screenWidth/2 - 180, 250, "Click to Select Game Mode:");
    
    // Draw menu boxes
    setcolor(GREEN);
    rectangle(250, 320, 550, 370);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(280, 335, "1. Single Player");
    
    setcolor(CYAN);
    rectangle(250, 400, 550, 450);
    setcolor(WHITE);
    outtextxy(280, 415, "2. Multiplayer");
    
    setcolor(RED);
    rectangle(250, 480, 550, 530);
    setcolor(WHITE);
    outtextxy(320, 495, "3. Exit");
    
    // Wait for mouse click
    int mouseX, mouseY;
    while (!ismouseclick(WM_LBUTTONDOWN)) {
        delay(100);
    }
    
    getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
    
    // Check which option was clicked
    if (mouseX >= 250 && mouseX <= 550) {
        if (mouseY >= 320 && mouseY <= 370) {
            setupPlayers(SINGLE_PLAYER);
            mode = SINGLE_PLAYER;
        } else if (mouseY >= 400 && mouseY <= 450) {
            setupPlayers(MULTIPLAYER);
            mode = MULTIPLAYER;
        } else if (mouseY >= 480 && mouseY <= 530) {
            gameRunning = false;
        }
    }
}

void Game::setupPlayers(GameMode selectedMode) {
    // Clean up old players if any
    if (player1 != nullptr) delete player1;
    if (player2 != nullptr) delete player2;
    
    if (selectedMode == SINGLE_PLAYER) {
        player1 = new HumanPlayer('X');
        player2 = new ComputerPlayer('O');
    } else {
        player1 = new HumanPlayer('X');
        player2 = new HumanPlayer('O');
    }
    
    currentPlayer = player1;
    winner = ' ';
    board->reset();
}

void Game::run() {
    while (gameRunning) {
        if (mode == MENU) {
            showMenu();
        } else if (mode == SINGLE_PLAYER || mode == MULTIPLAYER) {
            cleardevice();
            render();
            handleInput();
            update();
            checkGameStatus();
        } else if (mode == GAME_OVER) {
            displayResult();
            if (askPlayAgain()) {
                mode = MENU;
            } else {
                gameRunning = false;
            }
        }
        delay(100);
    }
}

void Game::handleInput() {
    int cellIndex = -1;
    
    // Check if current player is human or computer
    HumanPlayer* humanPlayer = dynamic_cast<HumanPlayer*>(currentPlayer);
    ComputerPlayer* computerPlayer = dynamic_cast<ComputerPlayer*>(currentPlayer);
    
    if (humanPlayer != nullptr) {
        // Human player - wait for mouse click
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mouseX, mouseY;
            getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
            cellIndex = board->getCellFromClick(mouseX, mouseY);
        }
    } else if (computerPlayer != nullptr) {
        // Computer player - get AI move
        delay(500); // Small delay for better UX
        cellIndex = computerPlayer->getBestMove(board);
    }
    
    // Make the move if valid
    if (cellIndex != -1 && board->isCellEmpty(cellIndex)) {
        board->setCellMark(cellIndex, currentPlayer->getMark());
        switchPlayer();
    }
}

void Game::update() {
    // Game logic is handled in checkGameStatus
}

void Game::render() {
    // Draw title
    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    
    if (mode == SINGLE_PLAYER) {
        outtextxy(250, 50, "Single Player Mode");
    } else {
        outtextxy(270, 50, "Multiplayer Mode");
    }
    
    // Display current player
    char turnText[50];
    sprintf(turnText, "Current Turn: Player %c", currentPlayer->getMark());
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(250, 90, turnText);
    
    // Draw the board and marks
    board->drawGrid();
    board->drawMarks();
}

void Game::switchPlayer() {
    if (currentPlayer == player1) {
        currentPlayer = player2;
    } else {
        currentPlayer = player1;
    }
}

void Game::checkGameStatus() {
    // Check if X wins
    if (board->checkWin('X')) {
        winner = 'X';
        mode = GAME_OVER;
        return;
    }
    
    // Check if O wins
    if (board->checkWin('O')) {
        winner = 'O';
        mode = GAME_OVER;
        return;
    }
    
    // Check for draw
    if (board->checkDraw()) {
        winner = 'D';
        mode = GAME_OVER;
        return;
    }
}

void Game::displayResult() {
    cleardevice();
    setbkcolor(BLACK);
    
    // Display result
    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(250, 150, "GAME OVER!");
    
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    
    if (winner == 'D') {
        outtextxy(280, 250, "It's a Draw!");
    } else {
        char resultText[50];
        sprintf(resultText, "Player %c Wins!", winner);
        outtextxy(260, 250, resultText);
    }
    
    // Draw final board state
    Board tempBoard(100, 300, 320);
    for (int i = 0; i < 9; i++) {
        tempBoard.setCellMark(i, board->getCellMark(i));
    }
    tempBoard.drawGrid();
    tempBoard.drawMarks();
}

void Game::displayMessage(const char* message, int y) {
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(screenWidth/2 - 100, y, const_cast<char*>(message));
}

bool Game::askPlayAgain() {
    setcolor(GREEN);
    rectangle(250, 480, 550, 530);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(280, 495, "Play Again? (Click)");
    
    setcolor(RED);
    rectangle(250, 550, 550, 600);
    setcolor(WHITE);
    outtextxy(320, 565, "Exit (Click)");
    
    // Wait for mouse click
    while (!ismouseclick(WM_LBUTTONDOWN)) {
        delay(100);
    }
    
    int mouseX, mouseY;
    getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
    
    if (mouseX >= 250 && mouseX <= 550) {
        if (mouseY >= 480 && mouseY <= 530) {
            return true; // Play again
        } else if (mouseY >= 550 && mouseY <= 600) {
            return false; // Exit
        }
    }
    
    return false;
}

void Game::cleanup() {
    if (board != nullptr) {
        delete board;
        board = nullptr;
    }
    if (player1 != nullptr) {
        delete player1;
        player1 = nullptr;
    }
    if (player2 != nullptr) {
        delete player2;
        player2 = nullptr;
    }
}
