#ifndef FIGURERIGHTL_HPP
#define FIGURERIGHTL_HPP

#include <QMainWindow>
#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class FigureRightL : public Figure
{
public:
    FigureRightL(QMainWindow *game_window, QColor tile_color);
    ~FigureRightL() override;
};

#endif // FIGURERIGHTL_HPP
