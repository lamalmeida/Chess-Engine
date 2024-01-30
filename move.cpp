#include "move.hpp"

using namespace std;

constexpr int SOURCE_MASK = 0x3f;
constexpr int TARGET_MASK = 0x3f << 6;
constexpr int TYPE_MASK = 0xf << 12; 
constexpr int CAPTURE_FLAG = 1 << 14;
constexpr int PROMO_FLAG = 1 << 15;

Move::Move(int source, int target, MoveType moveType): move{0} {
    move |= source | target << 6 | moveType << 12;
}
Move::Move(EncMove move): move{move} {}

int Move::getSource() const {
    return static_cast<int>(move & SOURCE_MASK);
}

int Move::getTarget() const {
    return static_cast<int>((move & TARGET_MASK) >> 6);
}

MoveType Move::getMoveType() const {
    return static_cast<MoveType>((move & TYPE_MASK) >> 12);
}

bool Move::isPromotion() const {
    return move & PROMO_FLAG;
}

bool Move::isCapture() const {
    return move & CAPTURE_FLAG;
}

bool Move::isCastle() const {
    MoveType type = getMoveType();
    return type == K_CASTLE || type == Q_CASTLE;
} 

bool Move::isEnpassant() const {
    return getMoveType() == EN_PASSANT;
}

std::ostream& operator<<(std::ostream& out, const Move& move) {
    int source = move.getSource();
    int target = move.getTarget();
    MoveType type = move.getMoveType();

    return out << "(" << positions[source] << ", " << positions[target] << ", " << moveTypeStr[type] << ")" << endl;
}