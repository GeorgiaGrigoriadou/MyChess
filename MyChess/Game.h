#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "player.h"
#include "ChessBoard.h"
#include "Background.h"

class Game {
private:
	Chessboard chessboard;
	Background background;

	string player;

	Piece* active_piece = nullptr;
	vector<Move>* possibleMoves = nullptr;
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();

	void start();
	void end();
};