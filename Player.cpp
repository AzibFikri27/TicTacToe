#include "Player.h"

Player::Player(char m) : mark(m), score(0) {}

Player::~Player() {}

char Player::getMark() const {
    return mark;
}

int Player::getScore() const {
    return score;
}

void Player::setMark(char m) {
    mark = m;
}

void Player::setScore(int s) {
    score = s;
}

void Player::incrementScore() {
    score++;
}
