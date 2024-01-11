#pragma once

#include <iostream>
#include <vector>

#include "Move.h"
#include "Piece.h"

using namespace std;

class Chessboard {
public:
	Piece* board[8][8];
	
	void setup();
	void place(Piece* p);	

	void draw();

	Piece* getClickedPiece(float mx, float my);
};

