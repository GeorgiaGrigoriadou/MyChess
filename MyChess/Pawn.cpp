#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(string color, int col) : Piece("Pawn", color) {
	if (color == "black") {
		row = 1;
	}
	else {
		row = 6;
	}

	this->col = col;
}
vector<Move>* Pawn::getPossibleMoves(Chessboard* chessboard) {
	vector<Move>* moves = new vector<Move>();

	int cx = this->col;
	int cy = this->row;


	

	for (int i = cy - 1, j = cx; i >= 0 && j >= 0 && i < 8 && j < 8; i--) { // up
		if (chessboard->board[i][j] != nullptr) {
			if (chessboard->board[i][j]->color != this->color) {
				Move m(i, j);
				moves->push_back(m);
			}
			break;
		}
		Move m(i, j);
		moves->push_back(m);
		break;
	}



	return moves;
}
