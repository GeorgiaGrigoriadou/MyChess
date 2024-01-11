#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Move.h"

using namespace std;

class Rook : public Piece {
public:
	Rook(string color, int col);

	virtual vector<Move>* getPossibleMoves(class Chessboard* chessboard);
};

