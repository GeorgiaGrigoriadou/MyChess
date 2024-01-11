#include "Bishop.h"

#include "ChessBoard.h"

Bishop::Bishop(string color, int col) : Piece("Bishop", color) {
	if (color == "black") {
		row = 0;
	}
	else {
		row = 7;
	}

	this->col = col;
}


vector<Move>* Bishop::getPossibleMoves(Chessboard* chessboard) {
	vector<Move>* moves = new vector<Move>();

	int cx = this->col;
	int cy = this->row;

	for (int i = cy + 1, j = cx + 1; i >= 0 && j >= 0 && i < 8 && j < 8; i++, j++) { // down right
		if (chessboard->board[i][j] != nullptr) {
			if (chessboard->board[i][j]->color != this->color) {
				Move m(i, j);
				moves->push_back(m);
			}
			break;
		}
		Move m(i, j);
		moves->push_back(m);
	}

	for (int i = cy - 1, j = cx - 1; i >= 0 && j >= 0 && i < 8 && j < 8; i--, j--) { // upper left
		if (chessboard->board[i][j] != nullptr) {
			break;
		}
		Move m(i, j);
		moves->push_back(m);
	}

	for (int i = cy + 1, j = cx - 1; i >= 0 && j >= 0 && i < 8 && j < 8; i++, j--) { // down left
		if (chessboard->board[i][j] != nullptr) {
			if (chessboard->board[i][j]->color != this->color) {
				Move m(i, j);
				moves->push_back(m);
			}
			break;
		}
		Move m(i, j);
		moves->push_back(m);
	}

	for (int i = cy - 1, j = cx + 1; i >= 0 && j >= 0 && i < 8 && j < 8; i--, j++) { // upper right
		if (chessboard->board[i][j] != nullptr) {
			if (chessboard->board[i][j]->color != this->color) {
				Move m(i, j);
				moves->push_back(m);
			}
			break;
		}
		Move m(i, j);
		moves->push_back(m);
	}
	

	return moves;
}

