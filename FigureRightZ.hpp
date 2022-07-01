#ifndef FIGURERIGHTZ_HPP
#define FIGURERIGHTZ_HPP

#include <QMainWindow>
#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class FigureRightZ : public Figure
{
public:
    FigureRightZ(QMainWindow *game_window, QColor tile_color);
    ~FigureRightZ() override;
};

#endif // FIGURERIGHTZ_HPP
