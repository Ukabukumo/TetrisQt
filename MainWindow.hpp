#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QWidget>
#include <QGraphicsPixmapItem>

#include "Tile.hpp"
#include "Stick.hpp"
#include "Block.hpp"
#include "FigureRightL.hpp"
#include "FigureLeftL.hpp"
#include "FigureRightZ.hpp"
#include "FigureLeftZ.hpp"
#include "FigureT.hpp"
#include "Figure.hpp"
#include "TileHeap.hpp"
#include "GlobalParams.h"
#include "InfoField.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void Lose();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    TileHeap *tile_heap;
    Figure *figure;
    FigureType figure_type;
    FigureType next_figure = static_cast<FigureType>(QRandomGenerator::global()->bounded(nTypes));
    InfoField *info_field;

    QDialog *menu;
    QVBoxLayout *box;
    QLabel *score_title;
    QPushButton *start_btn;
    QPushButton *exit_btn;

    QGraphicsScene fieldScene;
    QGraphicsView fieldView;
    QGraphicsScene next_fig_scene;
    QGraphicsView next_fig_view;
    QGraphicsPixmapItem *field;
    QGraphicsPixmapItem *next_fig_field;
    QGraphicsPixmapItem *score_field;

    int game_timer_id;
    bool in_game = false;

    void CreateWindow();
    void CreatePauseMenu();
    void PauseMenu();
    void CreateConnections();
    void SpawnFigure();
    void DrawFigure();
    void CheckStopFall();
    void CheckStopLeft();
    void CheckStopRight();
    bool CheckLose();
    void Control(int key);
    void Restart();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_HPP
