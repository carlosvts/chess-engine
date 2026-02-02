#include "types.hpp"

/*
    This enum (uint8_t for bitwise)
    allows us to pass one of his elements into the Move::flags 
*/
enum MoveFlag : uint8_t
{
    NO_FLAG             = 0,

    CAPTURE             = 1 << 0,
    DOUBLE_PAWN_PUSH    = 1 << 1,
    EN_PASSANT          = 1 << 2,
    CASTLING            = 1 << 3,
    PROMOTION           = 1 << 4
};

struct Move 
{
    Square from;
    Square to;

    Piece movingPiece;
    Piece capturedPiece;

    Piece promotionPiece; // NO_PIECE if no promotion

    MoveFlag flags; // CAPTURES, PROMOTION, ENPASSANT, CASTLING, DOUBLE_PAWN_PUSH

    // By which color is this square beeing attacked?
    // Should work as isSquareAttacked(E1, BLACK) --> true or false
    bool isSquareAttacked(Square square, Color byColor) const;
};

