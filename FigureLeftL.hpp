#ifndef FIGURELEFTL_HPP
#define FIGURELEFTL_HPP

#include <QMainWindow>
#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class FigureLeftL : public Figure
{
public:
    FigureLeftL(QMainWindow *game_window, QColor tile_color);
    ~FigureLeftL() override;
};

#endif // FIGURELEFTL_H
