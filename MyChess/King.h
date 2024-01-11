#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Move.h"

class King : public Piece {
public:
	King(string color);

	virtual vector<Move>* getPossibleMoves(class Chessboard* chessboard);
};


