# Object-Oriented Programming Concepts in Tic-Tac-Toe

This document explains how various OOP concepts are implemented in this Tic-Tac-Toe game.

## 1. Encapsulation

All classes in this project demonstrate encapsulation by having private data members with public getter and setter methods for controlled access.

### Examples:

**Shape Class** (Shape.h):
```cpp
class Shape {
private:
    int x;        // Private data members
    int y;
    int color;

public:
    // Public getters
    int getX() const;
    int getY() const;
    int getColor() const;
    
    // Public setters
    void setX(int xPos);
    void setY(int yPos);
    void setColor(int col);
};
```

**Player Class** (Player.h):
```cpp
class Player {
private:
    char mark;    // Private data members
    int score;

public:
    char getMark() const;      // Public getter
    void setMark(char m);      // Public setter
};
```

This ensures data integrity and prevents unauthorized access to internal state.

## 2. Inheritance

The project demonstrates inheritance through two hierarchies:

### Shape Hierarchy:
- **Base Class**: `Shape` (abstract base class)
- **Derived Classes**: `Cross` and `Circle`

```cpp
// Shape.h - Base class
class Shape {
    virtual void draw() = 0;  // Pure virtual function
};

// Cross.h - Derived class
class Cross : public Shape {
    void draw() override;     // Implements base class method
};

// Circle.h - Derived class  
class Circle : public Shape {
    void draw() override;     // Implements base class method
};
```

### Player Hierarchy:
- **Base Class**: `Player` (abstract base class)
- **Derived Classes**: `HumanPlayer` and `ComputerPlayer`

```cpp
// Player.h - Base class
class Player {
    virtual int getMove() = 0;  // Pure virtual function
};

// HumanPlayer.h - Derived class
class HumanPlayer : public Player {
    int getMove() override;     // Gets move from mouse click
};

// ComputerPlayer.h - Derived class
class ComputerPlayer : public Player {
    int getMove() override;     // AI-generated move
};
```

## 3. Polymorphism

Polymorphism is achieved through virtual functions, allowing objects of different classes to be treated uniformly.

### Runtime Polymorphism Examples:

**1. Shape Drawing:**
```cpp
// In Board.cpp
Shape* shape = nullptr;
if (mark == 'X') {
    shape = new Cross(...);  // Creates Cross object
} else {
    shape = new Circle(...); // Creates Circle object
}
shape->draw();  // Calls appropriate draw() based on actual type
```

**2. Player Moves:**
```cpp
// In Game.cpp
Player* currentPlayer;  // Can point to HumanPlayer or ComputerPlayer

// Polymorphic call - behavior depends on actual player type
HumanPlayer* humanPlayer = dynamic_cast<HumanPlayer*>(currentPlayer);
ComputerPlayer* computerPlayer = dynamic_cast<ComputerPlayer*>(currentPlayer);

if (humanPlayer != nullptr) {
    // Handle human player input
} else if (computerPlayer != nullptr) {
    // Handle computer player AI
}
```

## 4. Composition

Composition represents a "has-a" relationship where one class owns another class's objects.

### Cell and Shape Composition:

The `Cell` class **owns** a `Shape` object and manages its complete lifecycle:

```cpp
// Cell.h
class Cell {
private:
    Shape* shape;  // Cell owns the Shape
    
public:
    Cell(int r = 0, int c = 0);
    ~Cell() {
        // Cell is responsible for deleting the Shape
        if (shape != nullptr) {
            delete shape;
        }
    }
};
```

**Key Points:**
- Cell creates and destroys Shape objects
- Shape cannot exist without Cell
- When Cell is destroyed, Shape is automatically destroyed
- This is a strong ownership relationship

## 5. Aggregation

Aggregation represents a "has-a" relationship where objects can exist independently.

### Game and Board/Player Aggregation:

```cpp
// Game.h
class Game {
private:
    Board* board;      // Game uses Board
    Player* player1;   // Game uses Players
    Player* player2;
};
```

**Key Points:**
- Game aggregates Board and Player objects
- These objects could theoretically exist independently
- Game manages them during gameplay but doesn't own them in the strictest sense
- This is a weaker relationship than composition

### Board and Cell Aggregation:

```cpp
// Board.h
class Board {
private:
    Cell cells[9];  // Board aggregates 9 Cell objects
};
```

## 6. Array of Objects

The `Board` class uses an array of `Cell` objects to represent the 3x3 grid:

```cpp
// Board.h
class Board {
private:
    Cell cells[9];  // Array of 9 Cell objects
    
public:
    Cell& getCell(int index) {
        return cells[index];
    }
};
```

**Usage in Board.cpp:**
```cpp
// Initialize cells
for (int i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;
    cells[i].setRow(row);
    cells[i].setCol(col);
}
```

## 7. Abstract Classes and Interfaces

Both `Shape` and `Player` serve as abstract base classes:

```cpp
// Shape.h - Abstract class
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual = abstract
    virtual ~Shape();
};

// Player.h - Abstract class
class Player {
public:
    virtual int getMove() = 0;  // Pure virtual = abstract
    virtual ~Player();
};
```

These cannot be instantiated directly and force derived classes to implement the pure virtual methods.

## 8. Virtual Destructors

All base classes with virtual functions have virtual destructors:

```cpp
class Shape {
public:
    virtual ~Shape();  // Virtual destructor ensures proper cleanup
};

class Player {
public:
    virtual ~Player();  // Virtual destructor for polymorphic deletion
};
```

This ensures proper cleanup when deleting derived class objects through base class pointers.

## Class Diagram Overview

```
                    Shape (abstract)
                    /           \
                Cross           Circle
                
                    Player (abstract)
                    /              \
            HumanPlayer      ComputerPlayer
            
                    Cell
                     |
                  (owns Shape)
                  
                    Board
                     |
                (aggregates Cell[9])
                
                    Game
                   /    \
              (aggregates Board, Players)
```

## Design Patterns Used

1. **Factory Pattern**: Shape creation in Board::setCellMark()
2. **Strategy Pattern**: Different player strategies (Human vs Computer)
3. **State Pattern**: Game modes (MENU, SINGLE_PLAYER, MULTIPLAYER, GAME_OVER)

## Conclusion

This project demonstrates comprehensive use of OOP principles:
- ✅ Encapsulation through private data and public interfaces
- ✅ Inheritance through Shape and Player hierarchies
- ✅ Polymorphism through virtual functions
- ✅ Composition through Cell owning Shape
- ✅ Aggregation through Game using Board and Players
- ✅ Array of Objects through Cell array in Board
