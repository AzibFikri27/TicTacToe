#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int xPos = 0, int yPos = 0, int rad = 40, int col = 15);
    
    // Getter and Setter
    int getRadius() const;
    void setRadius(int rad);
    
    // Override draw method
    void draw() override;
};

#endif
