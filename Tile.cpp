#include "Tile.hpp"

Tile::Tile()
{
}

Tile::Tile(int x, int y, int tile_size, QColor tile_color)
{
    pos.setX(x);
    pos.setY(y);
    size = tile_size;
    color = tile_color;
}

void Tile::SetPos(QPoint new_pos)
{
    pos = new_pos;
}

QPoint Tile::GetPos()
{
    return pos;
}

QRect Tile::GetRect()
{
    QRect rect(pos.x(), pos.y(), size, size);
    return rect;
}

QColor Tile::GetColor()
{
    return color;
}

int Tile::GetSize()
{
    return size;
}

bool Tile::operator==(const Tile &tile)
{
    if (this->GetPos() == tile.pos)
    {
        return true;
    }

    else
    {
        return false;
    }
}
