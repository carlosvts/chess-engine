#pragma once
#include <cstdint>

/* Namespaces */
using Bitboard = uint64_t; // Every bit is one square
using Square = int;  // A1 = 0, H8 = 63

/*     Enums  */
enum Color : int
{
    WHITE = 0,
    BLACK = 1,
    BOTH = 2, 
};

enum Piece : int {
    PAWN = 0,
    KNIGHT = 1,
    BISHOP = 2,
    ROOK = 3,
    QUEEN = 4,
    KING = 5,
    NO_PIECE = 6
};

enum Castling : uint8_t
{
    NO_CASTLING        = 0,

    WHITE_KINGSIDE     = 1 << 0, // White O-O
    WHITE_QUEENSIDE    = 1 << 1, // White O-O-O
    BLACK_KINGSIDE     = 1 << 2, // Black O-O
    BLACK_QUEENSIDE    = 1 << 3  // Black O-O-O
};

// Translating everything to power of 2
// So all of bitwise operations are valid
// [WARNING] Remember to use only PieceCode for bitwise
// E.g WHITE_CODE | PAWN_CODE gives a white pawn
enum PieceCode : uint8_t {
    EMPTY  = 0,

    PAWN_CODE   = 1 << 0,
    KNIGHT_CODE = 1 << 1,
    BISHOP_CODE = 1 << 2,
    ROOK_CODE   = 1 << 3,
    QUEEN_CODE  = 1 << 4,
    KING_CODE   = 1 << 5,

    WHITE_CODE  = 1 << 6,
    BLACK_CODE  = 1 << 7
};

/*
    Constants
*/
constexpr int COLORS = 2;
constexpr int PIECE_TYPES = 6;
constexpr int NUM_SQUARES = 64;
constexpr int OCCUPANCY = 3; // A square can be occupied by black, white or both
constexpr Square NO_SQUARE = -1; // No square available for enpassant