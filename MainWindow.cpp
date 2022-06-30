#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tile_heap = new TileHeap(this);
    info_field = new InfoField(this);

    CreateWindow();
    CreatePauseMenu();
    CreateConnections();

    SpawnFigure();

    game_timer_id = startTimer(200);

    in_game = true;
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if (in_game)
    {
        DrawFigure();
    }
}

void MainWindow::timerEvent(QTimerEvent *)
{
    if (in_game)
    {
        figure->MoveDown();
        CheckStopFall();

        repaint();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (in_game)
    {
        int key = event->key();
        Control(key);

        repaint();
    }
}

void MainWindow::CreateWindow()
{
    setFixedWidth(FIELD_WIDTH + INFO_FIELD_WIDTH);
    setFixedHeight(FIELD_HEIGHT);

    setStyleSheet("background-color:black;");
}

void MainWindow::CreatePauseMenu()
{
    menu = new QDialog(this, Qt::FramelessWindowHint);
    menu = new QDialog();

    box = new QVBoxLayout();

    QFont font;
    font.setBold(true);

    font.setPixelSize(20);

    score_title = new QLabel();
    score_title->setStyleSheet("background-color:grey;");
    score_title->setAlignment(Qt::AlignCenter);
    score_title->setFont(font);

    font.setPixelSize(15);

    start_btn = new QPushButton("START");
    start_btn->setStyleSheet("background-color:lightgrey;");
    start_btn->setFont(font);

    exit_btn = new QPushButton("EXIT");
    exit_btn->setStyleSheet("background-color:lightgrey");
    exit_btn->setFont(font);

    box->addWidget(score_title);
    box->addWidget(start_btn);
    box->addWidget(exit_btn);

    menu->setStyleSheet("background:grey;");

    menu->setLayout(box);
}

void MainWindow::CreateConnections()
{
    connect(start_btn, &QPushButton::clicked, this, [this]() {
        menu->accept();
        Restart();
        in_game = true;
    });
    connect(exit_btn, &QPushButton::clicked, this, [this]() {
        menu->reject();
        this->close();
    });
    connect(this, &MainWindow::Lose, this, [this]() {
        in_game = false;

        QString score_info;
        score_info.setNum(tile_heap->GetScore());
        score_title->setText(score_info);

        menu->exec();
        this->activateWindow();
    });
}

void MainWindow::SpawnFigure()
{
    figure_type = next_figure;
    next_figure = static_cast<FigureType>(QRandomGenerator::global()->bounded(3));

    switch (figure_type)
    {
        case STICK:
            figure = new Stick(this, Qt::red);
            break;

        case BLOCK:
            figure = new Block(this, Qt::blue);
            break;

        case FIGURE_LEFT_L:
            figure = new FigureLeftL(this, Qt::yellow);
            break;
    }
}

void MainWindow::DrawFigure()
{
    figure->Draw();
    tile_heap->Draw();
    info_field->Draw(next_figure, tile_heap->GetScore());
}

void MainWindow::CheckStopFall()
{
    if (figure->CollisionFigure(tile_heap->tile_heap) ||
            figure->CollisionFloor())
    {
        figure->MoveUp();
        tile_heap->SetFigure(*figure);

        if (CheckLose()) return;

        tile_heap->CheckLines();

        delete figure;
        SpawnFigure();
    }
}

void MainWindow::CheckStopLeft()
{
    if (figure->CollisionFigure(tile_heap->tile_heap) ||
            figure->CollisionLeftSide())
    {
        figure->MoveRight();
    }
}

void MainWindow::CheckStopRight()
{
    if (figure->CollisionFigure(tile_heap->tile_heap) ||
            figure->CollisionRightSide())
    {
        figure->MoveLeft();
    }
}

bool MainWindow::CheckLose()
{
    if (figure->CollisionCeil())
    {
        emit Lose();
        return true;
    }

    return false;
}

void MainWindow::Control(int key)
{
    switch (key)
    {
        case Qt::Key_Left:
            figure->MoveLeft();
            CheckStopLeft();
            break;

        case Qt::Key_Right:
            figure->MoveRight();
            CheckStopRight();
            break;

        case Qt::Key_Down:
            figure->MoveDown();
            CheckStopFall();
            break;

        case Qt::Key_Space:
            figure->Rotate(tile_heap->tile_heap);
            break;
    }
}

void MainWindow::Restart()
{
    delete figure;
    delete tile_heap;
    tile_heap = new TileHeap(this);
    next_figure = static_cast<FigureType>(QRandomGenerator::global()->bounded(3));;
    SpawnFigure();

    killTimer(game_timer_id);
    game_timer_id = startTimer(200);
}
