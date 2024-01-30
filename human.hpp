#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.hpp"

class Board;

class Human : public Player {
public:
    Human(int side);
    virtual int move(Board* chessBoard, std::istringstream &ss) override;
};

#endif