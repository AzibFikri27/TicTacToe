#include "Circle.h"
#include <graphics.h>

Circle::Circle(int xPos, int yPos, int rad, int col) 
    : Shape(xPos, yPos, col), radius(rad) {}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int rad) {
    radius = rad;
}

void Circle::draw() {
    setcolor(getColor());
    setlinestyle(SOLID_LINE, 0, 3);
    
    int x = getX();
    int y = getY();
    
    // Draw O shape (circle)
    circle(x, y, radius);
}
