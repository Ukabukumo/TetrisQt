#include "TileHeap.hpp"

TileHeap::TileHeap(QMainWindow *game_window)
{
    this->game_window = game_window;
}

TileHeap::~TileHeap()
{
    tile_heap.clear();
    score = 0;
}

void TileHeap::SetFigure(Figure figure)
{
    for (Tile &tile : figure.figure_tiles)
    {
        tile_heap.append(tile);
    }

    CheckLines();
}

void TileHeap::Draw(QPixmap *field_pix)
{
    QPainter qp(field_pix);

    for (Tile &tile : tile_heap)
    {
        qp.fillRect(tile.GetRect(), tile.GetColor());

        QPen pen;
        pen.setWidth(3);
        qp.setPen(pen);
        qp.drawRect(tile.GetRect());
    }
}

void TileHeap::CheckLines()
{
    int n_lines = 0;

    for (int i = FIELD_HEIGHT / TILE_SIZE - 1; i >= 0; --i)
    {
        bool isLine = true;

        do
        {
            QVector<int> line;

            for (int j = 0; j < FIELD_WIDTH / TILE_SIZE; ++j)
            {
                QPoint pos(j * TILE_SIZE, i * TILE_SIZE);

                isLine = false;

                for (Tile &tile : tile_heap)
                {
                    if (tile.GetPos() == pos)
                    {
                        line.append(tile_heap.indexOf(tile));
                        isLine = true;
                        break;
                    }
                }

                if (!isLine) break;
            }

            if (isLine)
            {
                n_lines++;

                qSort(line.begin(), line.end(), qGreater<int>());

                for (int i : line) tile_heap.remove(i);

                for (Tile &tile : tile_heap)
                {
                    if (tile.GetPos().y() < i * TILE_SIZE)
                    {
                        QPoint pos(tile.GetPos().x(), tile.GetPos().y() + TILE_SIZE);
                        tile.SetPos(pos);
                    }
                }
            }

            line.clear();

        } while (isLine);
    }

    CountScore(n_lines);
}

int TileHeap::GetScore()
{
    return score;
}

void TileHeap::CountScore(int n_lines)
{
    int res = n_lines * score_value;
    if (n_lines == 4) res *= 2;

    score += res;
}
