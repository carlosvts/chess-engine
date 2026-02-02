#pragma once

#include <vector>

#include "types.hpp"
#include "board.hpp"
#include "move.hpp"

/*
    declarations for pseudo-legal
    move generation.

    [IMPORTANT]
    - These functions generate PSEUDO-LEGAL moves
    that means the move respects the Piece movement but MAY NOT respect the game context
    (like moving a pinned piece)
    - King safety is NOT checked here
    - Final validation must be done via legality.hpp
*/

namespace MoveGen
{
    /*
        Generates all pseudo-legal moves for the side to move.

        - Appends moves to the vector
        - Does NOT clear the vector
        - Does NOT validate legality
    */
    void generatePseudoLegalMoves(const Board& board, std::vector<Move>& moves);

    /*
        Piece-specific generators
        Called internally by generatePseudoLegalMoves
    */

    void generatePawnMoves(const Board& board, std::vector<Move>& moves);

    void generateKnightMoves(const Board& board, std::vector<Move>& moves);

    void generateBishopMoves(const Board& board, std::vector<Move>& moves);

    void generateRookMoves(const Board& board, std::vector<Move>& moves);

    void generateQueenMoves(const Board& board, std::vector<Move>& moves);

    void generateKingMoves(const Board& board, std::vector<Move>& moves);
}
