#include <string>

#include "config.h"
#include "Helpers.h"
#include "graphics.h"

#include "Piece.h"

using namespace std;

Piece::Piece(string name, string color, int row, int col) : name(name), color(color), row(row), col(col) {
	texture = to_lower(color) + "_" + to_lower(name) + ".png";

	corner_x = CANVAS_WIDTH / 2 - CHESSBOARD_WIDTH / 2 + CELL_RADIUS;
	corner_y = CANVAS_HEIGHT / 2 - CHESSBOARD_HEIGHT / 2 + CELL_RADIUS;

	br.texture = std::string(ASSET_PATH) + texture;
	br.outline_opacity = 0.0f;
	br.fill_color[0] = 1;
	br.fill_color[1] = 1;
	br.fill_color[2] = 1;
	active = false;

	br_outline.outline_opacity = 1;	
	br_outline.fill_color[0] = 1;
	br_outline.fill_color[1] = 0;
	br_outline.fill_color[2] = 0;
	br_outline.fill_opacity = 0.7;
	br_outline.outline_color[0] = 1;
	br_outline.outline_color[1] = 0;
	br_outline.outline_color[2] = 0;

}

void Piece::draw() {	
	if (active) {
		graphics::drawDisk(corner_x + col * CELL_EDGE, corner_y + row * CELL_EDGE, CELL_RADIUS, br_outline);
	}
	graphics::drawRect(corner_x + col* CELL_EDGE, corner_y + row* CELL_EDGE, 50, 50, br);
}

