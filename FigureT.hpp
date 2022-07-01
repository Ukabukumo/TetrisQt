#ifndef FIGURET_HPP
#define FIGURET_HPP

#include <QMainWindow>
#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class FigureT : public Figure
{
public:
    FigureT(QMainWindow *game_window, QColor tile_color);
    ~FigureT() override;
};

#endif // FIGURET_HPP
