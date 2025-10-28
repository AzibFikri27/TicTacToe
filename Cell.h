#ifndef CELL_H
#define CELL_H

#include "Shape.h"

class Cell {
private:
    int row;
    int col;
    char mark;           // 'X', 'O', or ' '
    Shape* shape;        // Composition: Cell manages Shape's lifecycle
    int centerX;
    int centerY;

public:
    Cell(int r = 0, int c = 0);
    ~Cell();
    
    // Getters
    int getRow() const;
    int getCol() const;
    char getMark() const;
    int getCenterX() const;
    int getCenterY() const;
    
    // Setters
    void setRow(int r);
    void setCol(int c);
    void setMark(char m);
    void setCenterX(int x);
    void setCenterY(int y);
    
    // Methods
    bool isEmpty() const;
    void setShape(Shape* s);
    void drawShape();
};

#endif
