#include "Stick.hpp"

Stick::Stick(QMainWindow *game_window, QColor tile_color)
    : Figure(game_window, tile_color)
{
    QPoint spawn(FIELD_WIDTH/2, -TILE_SIZE);

    figure_tiles.append(*new Tile(spawn.x() - 2*TILE_SIZE, spawn.y(), TILE_SIZE, tile_color));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE,   spawn.y(), TILE_SIZE, tile_color));
    figure_tiles.append(*new Tile(spawn.x(),               spawn.y(), TILE_SIZE, tile_color));
    figure_tiles.append(*new Tile(spawn.x() + TILE_SIZE,   spawn.y(), TILE_SIZE, tile_color));
}

Stick::~Stick()
{
    figure_tiles.clear();
}
