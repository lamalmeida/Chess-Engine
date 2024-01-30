#ifndef __MOVE_H__
#define __MOVE_H__

#include <stdint.h>
#include <iostream>
#include "util.hpp"

// Move type defined following the From-To Based format
// https://www.chessprogramming.org/Encoding_Moves

struct Move {
    EncMove move; // 16-bit move encoding (6 source, 6 target, 4 flag)
    Move() = default;
    Move(int source, int target, MoveType moveType);
    Move(EncMove move);
    int getSource() const;
    int getTarget() const;
    MoveType getMoveType() const;
    bool isPromotion() const;
    bool isCapture() const;
    bool isCastle() const;
    bool isEnpassant() const;
    friend std::ostream& operator<<(std::ostream& out, const Move& move);
};

#endif