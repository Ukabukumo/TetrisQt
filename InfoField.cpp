#include "InfoField.hpp"

InfoField::InfoField(QMainWindow *game_window)
{
    this->game_window = game_window;
}

void InfoField::Draw(FigureType next_figure, int score)
{
    // Draw next figure
    switch (next_figure)
    {
        case STICK:
            DrawStick();
            break;

        case BLOCK:
            DrawBlock();
            break;

        case FIGURE_LEFT_L:
            DrawFigureLeftL();
            break;
    }

    QPainter qp(game_window);

    QPen pen;
    pen.setColor(Qt::lightGray);
    pen.setWidth(1);

    qp.setPen(pen);

    // Draw separator
    qp.drawLine(FIELD_WIDTH, 0, FIELD_WIDTH, FIELD_HEIGHT);

    // Draw figure box
    QPoint lu(FIELD_WIDTH + INFO_FIELD_WIDTH/2 - TILE_SIZE*2.5f, TILE_SIZE*1.5f); // Left-Up
    QPoint ru(FIELD_WIDTH + INFO_FIELD_WIDTH/2 + TILE_SIZE*2.5f, TILE_SIZE*1.5f); // Right-Up
    QPoint rd(FIELD_WIDTH + INFO_FIELD_WIDTH/2 + TILE_SIZE*2.5f, TILE_SIZE*6.5f); // Right-Down
    QPoint ld(FIELD_WIDTH + INFO_FIELD_WIDTH/2 - TILE_SIZE*2.5f, TILE_SIZE*6.5f); // Left-Down

    qp.drawLine(lu, ld); // Left line
    qp.drawLine(lu, ru); // Up line
    qp.drawLine(ru, rd); // Right line
    qp.drawLine(ld, rd); // Down line
}

void InfoField::DrawStick()
{
    QPoint spawn(FIELD_WIDTH + INFO_FIELD_WIDTH/2, TILE_SIZE*3.5);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - 2*TILE_SIZE, spawn.y(), TILE_SIZE, Qt::red));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE,   spawn.y(), TILE_SIZE, Qt::red));
    figure_tiles.append(*new Tile(spawn.x(),               spawn.y(), TILE_SIZE, Qt::red));
    figure_tiles.append(*new Tile(spawn.x() + TILE_SIZE,   spawn.y(), TILE_SIZE, Qt::red));

    QPainter qp(game_window);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawBlock()
{
    QPoint spawn(FIELD_WIDTH + INFO_FIELD_WIDTH/2, TILE_SIZE*3);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, Qt::blue));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y(), TILE_SIZE, Qt::blue));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::blue));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + TILE_SIZE, TILE_SIZE, Qt::blue));

    QPainter qp(game_window);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}

void InfoField::DrawFigureLeftL()
{
    QPoint spawn(FIELD_WIDTH + INFO_FIELD_WIDTH/2, TILE_SIZE*2.5f);
    QVector<Tile> figure_tiles;

    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y(), TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + TILE_SIZE, TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x() - TILE_SIZE, spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::yellow));
    figure_tiles.append(*new Tile(spawn.x(),             spawn.y() + 2*TILE_SIZE, TILE_SIZE, Qt::yellow));

    QPainter qp(game_window);

    for (int i = 0; i < 4; ++i)
    {
        qp.fillRect(figure_tiles[i].GetRect(), figure_tiles[i].GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(figure_tiles[i].GetRect());
    }
}
