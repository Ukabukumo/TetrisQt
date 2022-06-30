#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <QVector>
#include <QPainter>
#include <QMainWindow>
#include <QDebug>
#include <QtMath>

#include "Tile.hpp"
#include "GlobalParams.h"

class Figure
{
public:
    Figure(QMainWindow *game_window, QColor tile_color);
    void MoveDown();
    void MoveUp();
    void MoveLeft();
    void MoveRight();
    void Draw();
    bool CollisionFloor();
    bool CollisionCeil();
    bool CollisionLeftSide();
    bool CollisionRightSide();
    bool CollisionFigure(QVector<Tile> tiles);

    virtual void Rotate(QVector<Tile> tiles);
    virtual ~Figure();

    QVector<Tile> figure_tiles;
    int angle;

protected:
    QMainWindow *game_window;
    QColor tile_color;
};

#endif // FIGURE_HPP
