#pragma once
#include "types.hpp"

/*
    This file contains precomputed attack values for
    pieces tables never changes through the game
*/

namespace Attacks
{
    // Those bitboards stores all
    // possible squares that a piece can attack

    
    extern Bitboard knights[64];         // This two pieces doesnt have its attacks restricted by
    extern Bitboard king[64];            // Any other piece in the game

    extern Bitboard pawn[COLORS][64];    // Pawn depends on color (black and white attacks are "inverted")

    // Sliding pieces (more complex to calculate)
    extern Bitboard rookRays[64][4];     // North, South, East, West
    extern Bitboard bishopRays[64][4];   // NE, NW, SE, SW

    void pre_compute();                  // Pre computes all possible attacks
}