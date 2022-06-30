#ifndef STICK_HPP
#define STICK_HPP

#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class Stick : public Figure
{
public:
    Stick(QMainWindow *game_window, QColor tile_color);
    ~Stick();
};

#endif // STICK_HPP
