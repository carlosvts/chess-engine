#pragma once

#pragma once

#include "types.hpp"
#include "board.hpp"
#include "move.hpp"

/*
    legality.hpp

    This file is responsible for validating chess rules.
    It does NOT generate moves and does NOT modify board state.

    This file:
    - Determinates if a square is attacked
    - Detectects check
    - Validates move legality (king safety, castling rules, etc.)
    Only.
*/

namespace Legal
{
    /*
        Returns true if `square` is attacked by any piece
        of color `by`.

        Notes:
        - This function reasons in terms of ATTACKS, not moves.
        - Pawn attacks differ from pawn movement.
        - King attacks are considered normally (distance 1).
        - This function ignores pins and king safety of the attacking side (this is a job for legal moves).
    */
    bool isSquareAttacked(const Board& board, Square square, Color by);

    /*
        Returns true if the king of `side` is currently in check.

        Internally:
        - Locates the king square
        - Calls isSquareAttacked(...)
    */
    bool isKingInCheck(const Board& board, Color side);

    /*
        Returns true if the given move is legal according
        to chess rules.

        Expected behavior:
        - Applies the move on a temporary board (probably deepcopy)
        - Verifies king safety
        - Handles special rules (castling, en passant, promotion)
    */
    bool isMoveLegal(const Board& board, const Move& move);

    /*
        Validates castling-specific rules.

        This function is typically called internally
        by isMoveLegal when move.flags contains CASTLING.

        Checks include:
        - Castling rights
        - No pieces between king and rook
        - King not in check
        - Squares crossed by king are not attacked
    */
    bool isCastlingLegal(const Board& board, const Move& move);
}
