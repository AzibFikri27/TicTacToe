#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    char mark;       // 'X' or 'O'
    int score;

public:
    Player(char m = 'X');
    virtual ~Player();
    
    // Getters
    char getMark() const;
    int getScore() const;
    
    // Setters
    void setMark(char m);
    void setScore(int s);
    
    // Methods
    void incrementScore();
    
    // Virtual method for polymorphism - gets the move from the player
    virtual int getMove() = 0;
};

#endif
