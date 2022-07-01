#ifndef FIGURELEFTZ_HPP
#define FIGURELEFTZ_HPP

#include <QMainWindow>
#include <QtMath>

#include "Figure.hpp"
#include "GlobalParams.h"

class FigureLeftZ : public Figure
{
public:
    FigureLeftZ(QMainWindow *game_window, QColor tile_color);
    ~FigureLeftZ() override;
};

#endif // FIGURELEFTZ_HPP
