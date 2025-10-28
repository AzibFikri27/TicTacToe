# Quick Start Guide - Tic-Tac-Toe Game

## Prerequisites
- Windows OS
- C++ Compiler (MinGW, Code::Blocks, or Visual Studio)
- WinBGIm Library installed

## Installation Steps

### 1. Install WinBGIm Library
Download from: https://winbgim.codecutter.org/

### 2. Configure Compiler

#### For Code::Blocks:
```
Project → Build Options → Linker Settings
Add libraries:
- libbgi.a
- gdi32
- user32
- comdlg32
- winmm
- ole32
- oleaut32
```

#### For MinGW (Command Line):
```bash
make
```

### 3. Run the Game
```bash
./TicTacToe.exe
```

## Game Controls

### Menu Navigation
- Click on "Single Player" for AI opponent
- Click on "Multiplayer" for two human players
- Click on "Exit" to quit

### Gameplay
- Click on any empty cell to place your mark
- Player X always goes first
- Win by getting 3 in a row (horizontal, vertical, or diagonal)

### After Game Ends
- Click "Play Again" to start a new game
- Click "Exit" to close the application

## Project Structure

```
├── main.cpp              # Entry point with setup instructions
├── Game.h/cpp            # Main game logic and state management
├── Board.h/cpp           # Board representation and win detection
├── Cell.h/cpp            # Individual cell with shape composition
├── Player.h/cpp          # Base player class (abstract)
├── HumanPlayer.h/cpp     # Human player input handler
├── ComputerPlayer.h/cpp  # AI opponent with strategy
├── Shape.h/cpp           # Base shape class (abstract)
├── Cross.h/cpp           # X mark implementation
├── Circle.h/cpp          # O mark implementation
├── Makefile              # Build configuration
├── README.md             # Project documentation
└── OOP_CONCEPTS.md       # OOP implementation details
```

## AI Strategy

The computer opponent uses the following decision-making process:
1. **Win**: If there's a winning move, take it
2. **Block**: If opponent can win next turn, block them
3. **Center**: Take the center cell if available
4. **Corner**: Take a corner cell if available
5. **Random**: Take any remaining empty cell

## Troubleshooting

### "graphics.h: No such file or directory"
- WinBGIm library not installed or not in include path
- Solution: Install library and configure compiler paths

### "undefined reference to initgraph"
- WinBGIm library not linked
- Solution: Add libraries to linker settings

### Graphics window doesn't appear
- Ensure you're running on Windows
- Check if graphics driver is properly initialized
- Try running as administrator

## Features Implemented

✅ Single Player vs AI
✅ Multiplayer (2 human players)
✅ Graphical interface with WinBGIm
✅ Mouse-based controls
✅ Win/Draw detection
✅ Play again functionality
✅ Comprehensive OOP design
✅ Strategic AI opponent

## Code Quality

- **Encapsulation**: All data members are private
- **Inheritance**: Shape and Player hierarchies
- **Polymorphism**: Virtual functions for draw() and getMove()
- **Composition**: Cell owns Shape
- **Aggregation**: Game uses Board and Players
- **Array of Objects**: Board uses Cell[9]

## License
Educational project demonstrating OOP concepts in C++
