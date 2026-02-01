#pragma once
#include "types.hpp"

class Board
{
    public:
        // viewer, whats in square
        PieceCode piece_at(int square) const;


    private:
        PieceCode mailbox[64];
};