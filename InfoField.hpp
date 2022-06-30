#ifndef INFOFIELD_HPP
#define INFOFIELD_HPP

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

#include "GlobalParams.h"
#include "Tile.hpp"

class InfoField
{
public:
    InfoField(QMainWindow *game_window);
    void Draw(FigureType next_figure, int score);

private:
    QMainWindow *game_window;
    void DrawStick();
    void DrawBlock();
    void DrawFigureLeftL();
};

#endif // INFOFIELD_HPP
