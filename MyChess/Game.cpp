#include <iostream>

#include "Game.h"
#include "graphics.h"
#include "config.h"

using namespace std;

Game::Game() {
}

Game::~Game() {
}

void Game::init() {
	chessboard.setup();

	active_piece = nullptr;
	player = "white";
}


void Game::draw() {
	background.draw();
	chessboard.draw();

	if (possibleMoves != nullptr) {

		float corner_x = CANVAS_WIDTH / 2 - CHESSBOARD_WIDTH / 2 + CELL_RADIUS;
		float corner_y = CANVAS_HEIGHT / 2 - CHESSBOARD_HEIGHT / 2 + CELL_RADIUS;



		for (auto m : *possibleMoves) {
			int row = m.row;
			int col = m.col;

			graphics::Brush br_outline;
			br_outline.outline_opacity = 1;
			br_outline.fill_color[0] = 0;
			br_outline.fill_color[1] = 1;
			br_outline.fill_color[2] = 0;
			br_outline.fill_opacity = 0.7;
			br_outline.outline_color[0] = 0;
			br_outline.outline_color[1] = 1;
			br_outline.outline_color[2] = 0;

			graphics::drawDisk(corner_x + col * CELL_EDGE, corner_y + row * CELL_EDGE, MOVE_RADIUS, br_outline);
		}
	}
}

void Game::update() {
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	if (ms.button_left_released) {
		float mx = graphics::windowToCanvasX((float)ms.cur_pos_x);
		float my = graphics::windowToCanvasY((float)ms.cur_pos_y);
		
		Piece * clicked_piece = chessboard.getClickedPiece(mx, my);

		if (clicked_piece != nullptr) {
			cout << "You are : " << player << ". You clicked: " << clicked_piece->color << " " << clicked_piece->name << endl;

			if (clicked_piece->color == player) {
				if (active_piece != nullptr) {
					active_piece->active = false;
				}
				if (possibleMoves != nullptr) {
					delete possibleMoves;
				}

				clicked_piece->active = true;

				active_piece = clicked_piece;

				possibleMoves = active_piece->getPossibleMoves(&chessboard);
				
				cout << "Piece activated, Possible moves: \n";
				
				if (possibleMoves != nullptr) {
					for (auto m : *possibleMoves) {
						cout << m.row << ", " << m.col << endl;
					}
				} else{
					active_piece->active = false;
					cout << "This piece cannot move " << endl;
				}
			} else {
				cout << "This piece is not yours. " << endl;
			}
		} 
	}
}




