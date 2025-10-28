#ifndef SHAPE_H
#define SHAPE_H

class Shape {
private:
    int x;
    int y;
    int color;

public:
    Shape(int xPos = 0, int yPos = 0, int col = 15);
    virtual ~Shape();
    
    // Getters
    int getX() const;
    int getY() const;
    int getColor() const;
    
    // Setters
    void setX(int xPos);
    void setY(int yPos);
    void setColor(int col);
    
    // Virtual draw method for polymorphism
    virtual void draw() = 0;
};

#endif
