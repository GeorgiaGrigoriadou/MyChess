#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Move.h"

using namespace std;

class Queen : public Piece {
public:
	Queen(string color);

	virtual vector<Move> * getPossibleMoves(class Chessboard* chessboard);
};

