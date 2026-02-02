#pragma once
#include "types.hpp"
#include <cstdint>

/*
Invariants:
- piece_bitboard and mailbox must always be consistent
- occupancy[BOTH] == occupancy[WHITE] | occupancy[BLACK]
- Exactly one white king and one black king must exist
*/
class Board
{
    public:
    Board();
    void Reset(); // Reset board state, clears all data and set everything to default value 
                  // Also sets sideToMove = WHITE, canCastle = NO_CASTLING, empassantSquare = NO_SQUARE
    
    /*
        Functions
    */    
    // Computes occupancy from piece bitboards
    // It does not modify board state
    Bitboard computeOccupancy() const;
    
    Bitboard pieces(Color color, Piece piece) const;
    bool isSquareOccupied(Square square) const;
    void updateOccupancy();

    // getters
    // viewer, whats in square
    PieceCode getPieceAt(int square) const;
    Bitboard getOccupancy() const;
    Color getSideToMove() const;
    uint8_t getCastlingRight() const;
    Square getEnpassantSquare() const;

    private:
        // piece bitboard, stores valuable information for a piece (color and type)
        // [2][6]
        Bitboard pieceBitboard[COLORS][PIECE_TYPES];
        // [3]
        // all constants defined in types.hpp
        Bitboard occupancy[OCCUPANCY];  // WHITE, BLACK, BOTH. We can get BOTH by doing occupancy[0] | occupancy[1]

        Color sideToMove;
        uint8_t canCastle;      // stores if can castle or not
        Square enpassantSquare; // stores the square that can be enpassant'ed, otherwise -1
        
        // Mailbox representation of board
        // 0 ... 63
        // Fast lookup and analysis in algorithm
        // [ATTENTION]: must always be in sync with pieceBitboard
        PieceCode mailbox[64];
};