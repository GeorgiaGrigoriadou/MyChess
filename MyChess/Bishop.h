#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Move.h"

using namespace std;

class Bishop : public Piece {
public:
	Bishop(string color, int col);

	virtual vector<Move>* getPossibleMoves(class Chessboard* chessboard);
};


