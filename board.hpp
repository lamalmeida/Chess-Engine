#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <string>
#include <unordered_map>
#include "move.hpp"

class Board {
    struct MadeMove {
        EncMove move;
        char sourcePiece, targetPiece;
        int castlingRight;
    };
    private:
        int ply, fifty, castlingRight;
        std::unordered_map<char, BitBoard> pieceMaps; 
        BitBoard occupancyMaps[3]; 
        std::vector<std::vector<char>> playerPieces;
        std::vector<MadeMove> moveHistory;

        BitBoard pawnAttacks[2][BOARD_SIZE];   
        BitBoard knightAttacks[BOARD_SIZE];    
        BitBoard kingAttacks[BOARD_SIZE];      
        
        BitBoard bishopAttacks[BOARD_SIZE][512];    
        BitBoard rookAttacks[BOARD_SIZE][4096];      
        
        BitBoard bishopMasks[BOARD_SIZE]; 
        BitBoard rookMasks[BOARD_SIZE]; 

        void initializeBoard(std::string fen);
        void computeOccupancyMaps();
        void computeAttackBoards();
        void computeSliderAttacks(BitBoard mask, bool isBishop, int square);

        void generatePawnMoves(int side, std::vector<EncMove>& moveslist);
        void generateKnightMoves(int side, std::vector<EncMove>& moveslist);
        void generateBishopMoves(int side, std::vector<EncMove>& moveslist);
        void generateRookMoves(int side, std::vector<EncMove>& moveslist);
        void generateQueenMoves(int side, std::vector<EncMove>& moveslist);
        void generateKingMoves(int side, std::vector<EncMove>& moveslist);
        void generateSpecialMoves(int side, std::vector<EncMove>& moveslist);

        BitBoard getBishopAttacks(int square, BitBoard occupancy);
        BitBoard getRookAttacks(int square, BitBoard occupancy);
        BitBoard getQueenAttacks(int square, BitBoard occupancy);
    public:
        Board();

        void setSquare(char piece, int square); 
        void removeSquare(char piece, int square); 
        char getSquare(int square) const; 
        
        int getSide() const;
        BitBoard getOccupancyBySide(int side) const;
        BitBoard getEmptySquares() const;
        BitBoard getPieceBB(char piece);
        int getKingSquare(int side);
        bool isKingInCheck(int side);
        bool isSquareAttacked(int side, int square); 
        EncMove getLastMove(int side) const; 
        
        std::vector<EncMove> generatePseudoMoves(int side);
        std::vector<EncMove> generateLegalMoves(int side);
        
        int makeMove(EncMove move);
        int makeMove(std::string& source, std::string& target, char promote); 
        void undoMove();

        int checkGameState(int side);
        
        void render();
};

#endif