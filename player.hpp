#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <sstream>

class Board;

class Player {
    protected:
        int side;
    public:
        Player(int side);
        virtual ~Player();
        virtual int move(Board* chessBoard, std::istringstream& ss) = 0;
};

#endif