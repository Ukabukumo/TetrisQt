#ifndef TILE_HPP
#define TILE_HPP

#include <QColor>
#include <QPoint>
#include <QRect>

class Tile
{
public:
    Tile();
    Tile(int x, int y, int tile_size, QColor tile_color);
    void SetPos(QPoint new_pos);
    QPoint GetPos();
    QRect GetRect();
    QColor GetColor();
    int GetSize();
    bool operator==(const Tile &tile);

private:
    QPoint pos;
    int    size;
    QColor color;
};

#endif // TILE_HPP
