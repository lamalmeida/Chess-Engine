#include <iostream>

#include "human.hpp"
#include "board.hpp"

using namespace std;

Human::Human(int side) : Player{side} {}
int Human::move(Board* chessBoard, istringstream &ss) {
    string source, target;
    char promote = 'x';
    ss >> source;
    ss >> target;
    ss >> promote;
    int flag = chessBoard->makeMove(source, target, promote); 
    if (flag == ILLEGAL_MOVE) throw runtime_error("Illegal Move!");
    return flag;
}