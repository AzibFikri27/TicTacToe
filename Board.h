#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

class Board {
private:
    Cell cells[9];      // Array of Cell objects (aggregation)
    int gridSize;
    int cellSize;
    int startX;
    int startY;

public:
    Board(int sz = 100, int x = 100, int y = 100);
    
    // Getters
    int getGridSize() const;
    int getCellSize() const;
    int getStartX() const;
    int getStartY() const;
    Cell& getCell(int index);
    
    // Setters
    void setGridSize(int sz);
    void setCellSize(int sz);
    void setStartX(int x);
    void setStartY(int y);
    
    // Methods
    void drawGrid();
    void drawMarks();
    bool isCellEmpty(int index) const;
    void setCellMark(int index, char mark);
    char getCellMark(int index) const;
    bool checkWin(char mark);
    bool checkDraw();
    void reset();
    int getCellFromClick(int mouseX, int mouseY);
};

#endif
