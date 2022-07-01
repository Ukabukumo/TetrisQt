#ifndef GLOBALPARAMS_H
#define GLOBALPARAMS_H

#include <QGraphicsScene>
#include <QGraphicsView>

const int FIELD_WIDTH  = 250;
const int FIELD_HEIGHT = 500;
const int TILE_SIZE    = 25;
const int INFO_FIELD_WIDTH = 200;

enum FigureType
{
    STICK,
    BLOCK,
    FIGURE_RIGHT_L,
    FIGURE_LEFT_L,
    FIGURE_RIGHT_Z,
    FIGURE_LEFT_Z,
    FIGURE_T
};

const int nTypes = 7;

#endif // GLOBALPARAMS_H
