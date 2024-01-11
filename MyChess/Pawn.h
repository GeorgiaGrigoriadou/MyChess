#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Move.h"

using namespace std;

class Pawn : public Piece {
public:
	Pawn(string color, int col);

	virtual vector<Move>* getPossibleMoves(class Chessboard* chessboard);
};
