#include "Board.h"
#include "Cross.h"
#include "Circle.h"
#include <graphics.h>

Board::Board(int sz, int x, int y) 
    : gridSize(sz), cellSize(sz), startX(x), startY(y) {
    
    // Initialize cells with their positions
    for (int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        cells[i].setRow(row);
        cells[i].setCol(col);
        
        // Calculate center position for each cell
        int centerX = startX + col * cellSize + cellSize / 2;
        int centerY = startY + row * cellSize + cellSize / 2;
        cells[i].setCenterX(centerX);
        cells[i].setCenterY(centerY);
    }
}

int Board::getGridSize() const {
    return gridSize;
}

int Board::getCellSize() const {
    return cellSize;
}

int Board::getStartX() const {
    return startX;
}

int Board::getStartY() const {
    return startY;
}

Cell& Board::getCell(int index) {
    return cells[index];
}

void Board::setGridSize(int sz) {
    gridSize = sz;
}

void Board::setCellSize(int sz) {
    cellSize = sz;
}

void Board::setStartX(int x) {
    startX = x;
}

void Board::setStartY(int y) {
    startY = y;
}

void Board::drawGrid() {
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 2);
    
    // Draw vertical lines
    for (int i = 1; i < 3; i++) {
        int x = startX + i * cellSize;
        line(x, startY, x, startY + 3 * cellSize);
    }
    
    // Draw horizontal lines
    for (int i = 1; i < 3; i++) {
        int y = startY + i * cellSize;
        line(startX, y, startX + 3 * cellSize, y);
    }
}

void Board::drawMarks() {
    for (int i = 0; i < 9; i++) {
        cells[i].drawShape();
    }
}

bool Board::isCellEmpty(int index) const {
    if (index >= 0 && index < 9) {
        return cells[index].isEmpty();
    }
    return false;
}

void Board::setCellMark(int index, char mark) {
    if (index >= 0 && index < 9) {
        cells[index].setMark(mark);
        
        // Create appropriate shape based on mark
        if (mark == 'X') {
            Cross* cross = new Cross(cells[index].getCenterX(), 
                                    cells[index].getCenterY(), 
                                    cellSize / 2, 
                                    RED);
            cells[index].setShape(cross);
        } else if (mark == 'O') {
            Circle* circle = new Circle(cells[index].getCenterX(), 
                                       cells[index].getCenterY(), 
                                       cellSize / 3, 
                                       BLUE);
            cells[index].setShape(circle);
        }
    }
}

char Board::getCellMark(int index) const {
    if (index >= 0 && index < 9) {
        return cells[index].getMark();
    }
    return ' ';
}

bool Board::checkWin(char mark) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (cells[i*3].getMark() == mark && 
            cells[i*3 + 1].getMark() == mark && 
            cells[i*3 + 2].getMark() == mark) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (cells[i].getMark() == mark && 
            cells[i + 3].getMark() == mark && 
            cells[i + 6].getMark() == mark) {
            return true;
        }
    }
    
    // Check diagonals
    if (cells[0].getMark() == mark && 
        cells[4].getMark() == mark && 
        cells[8].getMark() == mark) {
        return true;
    }
    
    if (cells[2].getMark() == mark && 
        cells[4].getMark() == mark && 
        cells[6].getMark() == mark) {
        return true;
    }
    
    return false;
}

bool Board::checkDraw() {
    for (int i = 0; i < 9; i++) {
        if (cells[i].isEmpty()) {
            return false;
        }
    }
    return true;
}

void Board::reset() {
    for (int i = 0; i < 9; i++) {
        cells[i].setMark(' ');
        cells[i].setShape(nullptr);
    }
}

int Board::getCellFromClick(int mouseX, int mouseY) {
    // Check if click is within board bounds
    if (mouseX < startX || mouseX > startX + 3 * cellSize ||
        mouseY < startY || mouseY > startY + 3 * cellSize) {
        return -1;
    }
    
    // Calculate which cell was clicked
    int col = (mouseX - startX) / cellSize;
    int row = (mouseY - startY) / cellSize;
    
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return row * 3 + col;
    }
    
    return -1;
}
