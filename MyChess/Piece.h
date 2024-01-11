#pragma once

#include <string>

#include "config.h"
#include "Helpers.h"
#include "graphics.h"
#include "Move.h"
using namespace std;

class Piece {
public:
	const string name;
	const string color;	
	int row, col; // 0...7
	string texture;
	float corner_x;
	float corner_y;
	graphics::Brush br;
	graphics::Brush br_outline;
	bool active;


	Piece(string name, string color, int row = 0, int col = 0);
	void draw();

	virtual vector<Move> * getPossibleMoves(class Chessboard* chessboard) {
		return nullptr;
	}
};

