#include "Figure.hpp"

Figure::Figure(QMainWindow *game_window, QColor tile_color)
{
    this->game_window = game_window;
    this->tile_color = tile_color;

    angle = 0;
}

Figure::~Figure()
{
    figure_tiles.clear();
}

void Figure::MoveDown()
{
    for (Tile &tile : figure_tiles)
    {
        QPoint pos(tile.GetPos());
        pos.setY(pos.y() + tile.GetSize());
        tile.SetPos(pos);
    }
}

void Figure::MoveUp()
{
    for (Tile &tile : figure_tiles)
    {
        QPoint pos(tile.GetPos());
        pos.setY(pos.y() - tile.GetSize());
        tile.SetPos(pos);
    }
}

void Figure::MoveLeft()
{
    for (Tile &tile : figure_tiles)
    {
        QPoint pos(tile.GetPos());
        pos.setX(pos.x() - tile.GetSize());
        tile.SetPos(pos);
    }
}

void Figure::MoveRight()
{
    for (Tile &tile : figure_tiles)
    {
        QPoint pos(tile.GetPos());
        pos.setX(pos.x() + tile.GetSize());
        tile.SetPos(pos);
    }
}

void Figure::Draw(QPixmap *field_pix)
{
    QPainter qp(field_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::black);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void Figure::Rotate(QVector<Tile> tiles)
{
    QVector<Tile> origin_tiles = figure_tiles;
    QVector<int> axisX;
    QVector<int> axisY;

    float x0;
    float y0;
    float sumX = 0.0f;
    float sumY = 0.0f;

    for (auto &tile : figure_tiles)
    {
        if (!axisX.contains(tile.GetPos().x())) axisX.append(tile.GetPos().x());
        if (!axisY.contains(tile.GetPos().y())) axisY.append(tile.GetPos().y());
    }

    for (int &x : axisX) sumX += x;
    for (int &y : axisY) sumY += y;

    x0 = sumX / axisX.count();
    y0 = sumY / axisY.count();

    for (int i = 0; i < 4; ++i)
    {
        float x = x0 + (figure_tiles[i].GetPos().x() - x0) * qCos(qDegreesToRadians(90.0f)) -
                (figure_tiles[i].GetPos().y() - y0) * qSin(qDegreesToRadians(90.0f));
        float y = y0 + (figure_tiles[i].GetPos().x() - x0) * qSin(qDegreesToRadians(90.0f)) -
                (figure_tiles[i].GetPos().y() - y0) * qCos(qDegreesToRadians(90.0f));

        x = qRound(x);
        y = qRound(y);

        QPoint pos;

        x = x / 1.0f / TILE_SIZE;
        y = y / 1.0f / TILE_SIZE;

        if ((angle / 90 == 0))
        {
            pos.setX(qCeil(x) * TILE_SIZE);
            pos.setY(qCeil(y) * TILE_SIZE);
        }

        else if (angle / 90 == 1)
        {
            pos.setX(qFloor(x) * TILE_SIZE);
            pos.setY(qCeil(y) * TILE_SIZE);
        }

        else if (angle / 90 == 2)
        {
            pos.setX(qFloor(x) * TILE_SIZE);
            pos.setY(qFloor(y) * TILE_SIZE);
        }

        else
        {
            pos.setX(qCeil(x) * TILE_SIZE);
            pos.setY(qFloor(y) * TILE_SIZE);
        }

        figure_tiles[i].SetPos(pos);
    }

    while (CollisionLeftSide()) MoveRight();
    while (CollisionRightSide()) MoveLeft();

    if (CollisionFigure(tiles))
    {
        MoveLeft();
        if (CollisionFigure(tiles)) MoveRight();

        MoveRight();
        if (CollisionFigure(tiles)) MoveLeft();

        if (CollisionFigure(tiles) || CollisionLeftSide() || CollisionRightSide())
        {
            figure_tiles = origin_tiles;
        }
    }

    if (CollisionFloor()) figure_tiles = origin_tiles;

    angle = (angle + 90) % 360;
}

bool Figure::CollisionCeil()
{
    for (Tile &tile : figure_tiles)
    {
        if (tile.GetPos().y() < 0) return true;
    }

    return false;
}

bool Figure::CollisionFloor()
{
    for (Tile &tile : figure_tiles)
    {
        if (tile.GetPos().y() > FIELD_HEIGHT - TILE_SIZE) return true;
    }

    return false;
}

bool Figure::CollisionLeftSide()
{
    for (Tile &tile : figure_tiles)
    {
        if (tile.GetPos().x() < 0) return true;
    }

    return false;
}

bool Figure::CollisionRightSide()
{
    for (Tile &tile : figure_tiles)
    {
        if (tile.GetPos().x() > FIELD_WIDTH - TILE_SIZE) return true;
    }

    return false;
}

bool Figure::CollisionFigure(QVector<Tile> tiles)
{
    for (Tile &tile : figure_tiles)
    {
        for (Tile &other : tiles)
        {
            if (tile.GetPos().y() == other.GetPos().y() &&
                    tile.GetPos().x() == other.GetPos().x())
            {
                return true;
            }
        }
    }

    return false;
}


