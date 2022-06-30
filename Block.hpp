#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class Block : public Figure
{
public:
    Block(QMainWindow *game_window, QColor tile_color);
    ~Block();
};

#endif // BLOCK_HPP
