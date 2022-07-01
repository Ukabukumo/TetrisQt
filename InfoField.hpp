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
    void Draw(QPixmap *next_fig_pix, FigureType next_figure, int score);

private:
    QMainWindow *game_window;
    void DrawStick(QPixmap *next_fig_pix);
    void DrawBlock(QPixmap *next_fig_pix);
    void DrawFigureRightL(QPixmap *next_fig_pix);
    void DrawFigureLeftL(QPixmap *next_fig_pix);
    void DrawFigureLeftZ(QPixmap *next_fig_pix);
    void DrawFigureRightZ(QPixmap *next_fig_pix);
    void DrawFigureT(QPixmap *next_fig_pix);
};

#endif // INFOFIELD_HPP
