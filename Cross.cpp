#include "Cross.h"
#include <graphics.h>

Cross::Cross(int xPos, int yPos, int sz, int col) 
    : Shape(xPos, yPos, col), size(sz) {}

int Cross::getSize() const {
    return size;
}

void Cross::setSize(int sz) {
    size = sz;
}

void Cross::draw() {
    setcolor(getColor());
    setlinestyle(SOLID_LINE, 0, 3);
    
    int x = getX();
    int y = getY();
    int halfSize = size / 2;
    
    // Draw X shape
    line(x - halfSize, y - halfSize, x + halfSize, y + halfSize);
    line(x - halfSize, y + halfSize, x + halfSize, y - halfSize);
}
