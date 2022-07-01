#include "FigureRightL.hpp"

FigureRightL::FigureRightL(QMainWindow *game_window, QColor tile_color) :
    Figure(game_window, tile_color)
{
    QPoint spawn(FIELD_WIDTH/2, -3*TILE_SIZE);

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, tile_color));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, tile_color));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + 2*TILE_SIZE, TILE_SIZE, tile_color));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + 2*TILE_SIZE, TILE_SIZE, tile_color));
}

FigureRightL::~FigureRightL()
{
    figure_tiles.clear();
}
