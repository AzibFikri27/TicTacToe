#include "Shape.h"

Shape::Shape(int xPos, int yPos, int col) : x(xPos), y(yPos), color(col) {}

Shape::~Shape() {}

int Shape::getX() const {
    return x;
}

int Shape::getY() const {
    return y;
}

int Shape::getColor() const {
    return color;
}

void Shape::setX(int xPos) {
    x = xPos;
}

void Shape::setY(int yPos) {
    y = yPos;
}

void Shape::setColor(int col) {
    color = col;
}
