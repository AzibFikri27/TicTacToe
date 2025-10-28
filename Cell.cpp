#include "Cell.h"

Cell::Cell(int r, int c) 
    : row(r), col(c), mark(' '), shape(nullptr), centerX(0), centerY(0) {}

Cell::~Cell() {
    // Composition: Cell owns the shape, so delete it
    if (shape != nullptr) {
        delete shape;
        shape = nullptr;
    }
}

int Cell::getRow() const {
    return row;
}

int Cell::getCol() const {
    return col;
}

char Cell::getMark() const {
    return mark;
}

int Cell::getCenterX() const {
    return centerX;
}

int Cell::getCenterY() const {
    return centerY;
}

void Cell::setRow(int r) {
    row = r;
}

void Cell::setCol(int c) {
    col = c;
}

void Cell::setMark(char m) {
    mark = m;
}

void Cell::setCenterX(int x) {
    centerX = x;
}

void Cell::setCenterY(int y) {
    centerY = y;
}

bool Cell::isEmpty() const {
    return mark == ' ';
}

void Cell::setShape(Shape* s) {
    // Delete old shape if exists (composition)
    if (shape != nullptr) {
        delete shape;
    }
    shape = s;
}

void Cell::drawShape() {
    if (shape != nullptr) {
        shape->draw();
    }
}
