#ifndef CROSS_H
#define CROSS_H

#include "Shape.h"

class Cross : public Shape {
private:
    int size;

public:
    Cross(int xPos = 0, int yPos = 0, int sz = 50, int col = 15);
    
    // Getter and Setter
    int getSize() const;
    void setSize(int sz);
    
    // Override draw method
    void draw() override;
};

#endif
