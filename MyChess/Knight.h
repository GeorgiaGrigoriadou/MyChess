#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Move.h"

using namespace std;

class Knight : public Piece {
public:
	Knight(string color, int col);

	virtual vector<Move>* getPossibleMoves(class Chessboard* chessboard);
};
