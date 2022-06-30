#ifndef TILEHEAP_HPP
#define TILEHEAP_HPP

#include <QVector>
#include <QDebug>
#include <QMainWindow>
#include <QPainter>

#include "Tile.hpp"
#include "Figure.hpp"
#include "GlobalParams.h"

class TileHeap
{
public:
    QVector<Tile> tile_heap;

    TileHeap(QMainWindow *gameWindow);
    ~TileHeap();
    void SetFigure(Figure figure);
    void Draw();
    void CheckLines();
    int GetScore();

private:
    const int score_value = 10;

    QMainWindow *game_window;
    int score = 0;

    void CountScore(int n_lines);
};

#endif // TILEHEAP_HPP
