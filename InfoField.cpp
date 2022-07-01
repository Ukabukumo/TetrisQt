#include "InfoField.hpp"

InfoField::InfoField(QMainWindow *game_window)
{
    this->game_window = game_window;
}

void InfoField::Draw(QPixmap *next_fig_pix, FigureType next_figure, int score)
{
    // Draw next figure
    switch (next_figure)
    {
        case STICK:
            DrawStick(next_fig_pix);
            break;

        case BLOCK:
            DrawBlock(next_fig_pix);
            break;

        case FIGURE_RIGHT_L:
            DrawFigureRightL(next_fig_pix);
            break;

        case FIGURE_LEFT_L:
            DrawFigureLeftL(next_fig_pix);
            break;

        case FIGURE_RIGHT_Z:
            DrawFigureRightZ(next_fig_pix);
            break;

        case FIGURE_LEFT_Z:
            DrawFigureLeftZ(next_fig_pix);
            break;

        case FIGURE_T:
            DrawFigureT(next_fig_pix);
            break;
    }
}

void InfoField::DrawStick(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - 2*TILE_SIZE, spawn.y(), TILE_SIZE, Qt::red));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE,   spawn.y(), TILE_SIZE, Qt::red));
    figure_tiles.append(*new Tile(spawn.x(),               spawn.y(), TILE_SIZE, Qt::red));
    figure_tiles.append(*new Tile(spawn.x() + TILE_SIZE,   spawn.y(), TILE_SIZE, Qt::red));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawBlock(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, Qt::blue));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y(), TILE_SIZE, Qt::blue));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::blue));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + TILE_SIZE, TILE_SIZE, Qt::blue));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawFigureRightL(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::yellow));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawFigureLeftL(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x(),             spawn.y(), TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + TILE_SIZE, TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::yellow));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawFigureLeftZ(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, Qt::green));
    figure_tiles.append(*new Tile(spawn.x(), spawn.y(), TILE_SIZE, Qt::green));
    figure_tiles.append(*new Tile(spawn.x(), spawn.y() + TILE_SIZE, TILE_SIZE, Qt::green));
    figure_tiles.append(*new Tile(spawn.x() + TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::green));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawFigureRightZ(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x(), spawn.y(), TILE_SIZE, Qt::green));
    figure_tiles.append(*new Tile(spawn.x() + TILE_SIZE, spawn.y(), TILE_SIZE, Qt::green));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::green));
    figure_tiles.append(*new Tile(spawn.x(), spawn.y() + TILE_SIZE, TILE_SIZE, Qt::green));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawFigureT(QPixmap *next_fig_pix)
{
    QPoint spawn(TILE_SIZE*2, TILE_SIZE);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, Qt::cyan));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::cyan));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::cyan));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + TILE_SIZE, TILE_SIZE, Qt::cyan));

    QPainter qp(next_fig_pix);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}
