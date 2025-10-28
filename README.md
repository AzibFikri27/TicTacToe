# Graphical Tic-Tac-Toe Game in C++

A fully functional, graphical 2D Tic-Tac-Toe game built using the WinBGIm library in C++. This project demonstrates key Object-Oriented Programming (OOP) principles.

## Features

- **Graphical Interface**: Uses WinBGIm library for all graphics rendering
- **Single Player Mode**: Play against an AI opponent with strategic logic
- **Multiplayer Mode**: Two human players on the same computer
- **Mouse-based Controls**: Interactive gameplay with mouse clicks
- **Win/Draw Detection**: Automatic detection of game outcomes
- **Play Again Option**: Replay without restarting the application

## OOP Concepts Demonstrated

### 1. Encapsulation
All classes have private data members with public getters/setters for controlled access.

### 2. Inheritance
- Base `Shape` class → `Cross` and `Circle` classes
- Base `Player` class → `HumanPlayer` and `ComputerPlayer` classes

### 3. Polymorphism
Virtual functions used for:
- `draw()` method in Shape hierarchy
- `getMove()` method in Player hierarchy

### 4. Association
- **Composition**: `Cell` owns `Shape` objects (manages lifecycle)
- **Aggregation**: `Game` aggregates `Board` and `Player` objects

### 5. Array of Objects
`Board` class uses an array of 9 `Cell` objects to represent the 3x3 grid.

## File Structure

```
TicTacToe/
├── main.cpp              # Entry point
├── Game.h/cpp            # Game loop, player turns, game states
├── Board.h/cpp           # Game board, grid drawing, win/draw detection
├── Cell.h/cpp            # Individual cell representation
├── Player.h/cpp          # Base player class
├── HumanPlayer.h/cpp     # Human player implementation
├── ComputerPlayer.h/cpp  # AI opponent implementation
├── Shape.h/cpp           # Base shape class
├── Cross.h/cpp           # X shape implementation
├── Circle.h/cpp          # O shape implementation
└── Makefile              # Build configuration
```

## Setup and Installation

### Prerequisites
- Windows OS
- MinGW/GCC compiler or Code::Blocks/Visual Studio
- WinBGIm library

### WinBGIm Library Installation

1. Download WinBGIm from: https://winbgim.codecutter.org/
2. Copy `graphics.h` and `winbgim.h` to your compiler's include directory
3. Copy `libbgi.a` to your compiler's lib directory

### Compilation

#### Using Makefile (MinGW):
```bash
make
```

#### Using Code::Blocks:
1. Create a new project
2. Add all .cpp files to the project
3. Go to Project → Build Options → Linker Settings
4. Add these libraries:
   - libbgi.a
   - gdi32
   - user32
   - comdlg32
   - winmm
   - ole32
   - oleaut32
5. Build and run

#### Using Visual Studio:
1. Create a new C++ project
2. Add all .cpp and .h files
3. Configure include and lib directories
4. Add libraries in Project Properties → Linker → Input
5. Build and run

## How to Play

1. **Start the Game**: Run the executable
2. **Select Mode**: Click to choose Single Player or Multiplayer
3. **Make Moves**: Click on empty cells to place your mark (X or O)
4. **Win Condition**: Get three marks in a row (horizontal, vertical, or diagonal)
5. **Play Again**: After game ends, choose to play again or exit

## AI Strategy

The computer player uses the following strategy:
1. Try to win if possible
2. Block opponent from winning
3. Take center if available
4. Take a corner
5. Take any remaining cell

## License

This project is created for educational purposes to demonstrate OOP concepts in C++.