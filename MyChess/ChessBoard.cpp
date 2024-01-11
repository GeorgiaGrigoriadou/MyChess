#include "ChessBoard.h"
#include "config.h"

#include "graphics.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"



// TODO: implement c-tor (row and col)
// TODO: implement getPossibleMoves();

void Chessboard::setup() {
	string colors[2] = { "black", "white" };

	for (int i = 0; i < 2; i++) {
		place(new Queen(colors[i]));
		place(new King(colors[i]));
		place(new Rook(colors[i], 0));
		place(new Rook(colors[i], 7));
		place(new Pawn(colors[i], 0));
		place(new Pawn(colors[i], 1));
		place(new Pawn(colors[i], 2));
		place(new Pawn(colors[i], 3));
		place(new Pawn(colors[i], 4));
		place(new Pawn(colors[i], 5));
		place(new Pawn(colors[i], 6));
		place(new Pawn(colors[i], 7));
		place(new Knight(colors[i], 1));
		place(new Knight(colors[i], 6));
		place(new Bishop(colors[i], 2));
		place(new Bishop(colors[i], 5));
	}	
	
}

void  Chessboard::place(Piece* p) {
	this->board[p->row][p->col] = p;
}

void Chessboard::draw() {
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "chessboard.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CHESSBOARD_WIDTH, CHESSBOARD_HEIGHT, br);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr) {
				board[i][j]->draw();
			}
		}
	}
}

Piece* Chessboard::getClickedPiece(float mx, float my) {

	if (mx <= CANVAS_WIDTH / 2 - CHESSBOARD_WIDTH / 2 || mx >= CANVAS_WIDTH / 2 + CHESSBOARD_WIDTH / 2) {
		cout << "out of range x: " << mx << endl;
		return nullptr;
	}

	if (my <= CANVAS_HEIGHT / 2 - CHESSBOARD_HEIGHT / 2 || my >= CANVAS_HEIGHT / 2 + CHESSBOARD_HEIGHT / 2) {
		cout << "out of range y: " << my << endl;
		return nullptr;
	}

	int i = (my - (CANVAS_HEIGHT / 2 - CHESSBOARD_HEIGHT / 2)) / CELL_EDGE;
	int j = (mx - (CANVAS_WIDTH / 2 - CHESSBOARD_WIDTH / 2)) / CELL_EDGE;
	

	cout << "Square clicked: " << i << ", " << j << endl;

	return board[i][j];
}