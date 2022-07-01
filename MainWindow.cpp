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
    setFixedHeight(FIELD_HEIGHT + 20);

    setStyleSheet("background-color:grey;");

    fieldScene.setSceneRect(0, 0, FIELD_WIDTH + INFO_FIELD_WIDTH, FIELD_HEIGHT);
    fieldView.setFixedSize(FIELD_WIDTH + INFO_FIELD_WIDTH, FIELD_HEIGHT);
    fieldView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    fieldView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    fieldView.setFocusPolicy(Qt::NoFocus);
    fieldView.setScene(&fieldScene);
    fieldView.setStyleSheet("background-color:grey");

    QHBoxLayout *mainLayout = new QHBoxLayout();

    mainLayout->addWidget(&fieldView);

    QWidget *wdg = new QWidget(this);
    wdg->setLayout(mainLayout);
    setCentralWidget(wdg);

    QPixmap field_pix(FIELD_WIDTH + 12, FIELD_HEIGHT);
    field = fieldScene.addPixmap(field_pix);

    QPixmap next_fig_pix(TILE_SIZE*4, TILE_SIZE*4);
    next_fig_field = fieldScene.addPixmap(next_fig_pix);

    QPixmap score_pix(TILE_SIZE*4, TILE_SIZE*2);
    score_field = fieldScene.addPixmap(score_pix);
}

void MainWindow::CreatePauseMenu()
{
    menu = new QDialog(this, Qt::FramelessWindowHint);

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
        menu->close();
        Restart();
        in_game = true;
    });
    connect(exit_btn, &QPushButton::clicked, this, [this]() {
        menu->close();
        this->close();
    });
    connect(this, &MainWindow::Lose, this, [this]() {
        in_game = false;

        QString score_info;
        score_info.setNum(tile_heap->GetScore());
        score_title->setText(score_info);

        menu->exec();
    });
}

void MainWindow::SpawnFigure()
{
    figure_type = next_figure;
    next_figure = static_cast<FigureType>(QRandomGenerator::global()->bounded(nTypes));

    switch (figure_type)
    {
        case STICK:
            figure = new Stick(this, Qt::red);
            break;

        case BLOCK:
            figure = new Block(this, Qt::blue);
            break;

        case FIGURE_RIGHT_L:
            figure = new FigureRightL(this, Qt::yellow);
            break;

        case FIGURE_LEFT_L:
            figure = new FigureLeftL(this, Qt::yellow);
            break;

        case FIGURE_RIGHT_Z:
            figure = new FigureRightZ(this, Qt::green);
            break;

        case FIGURE_LEFT_Z:
            figure = new FigureLeftZ(this, Qt::green);
            break;

        case FIGURE_T:
            figure = new FigureT(this, Qt::cyan);
            break;
    }
}

void MainWindow::DrawFigure()
{
    delete field;
    delete next_fig_field;
    delete score_field;

    QPixmap field_pix(FIELD_WIDTH, FIELD_HEIGHT);
    field_pix.fill(Qt::black);

    QPixmap next_fig_pix(TILE_SIZE*4, TILE_SIZE*4);
    next_fig_pix.fill(Qt::black);

    QPixmap score_pix(TILE_SIZE*6, TILE_SIZE*2);
    score_pix.fill(Qt::black);

    figure->Draw(&field_pix);
    tile_heap->Draw(&field_pix);
    info_field->Draw(&next_fig_pix, next_figure, tile_heap->GetScore());

    QPainter qp(&score_pix);
    QPen pen(Qt::white);
    qp.setPen(pen);
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    qp.setFont(font);
    QString score;
    score.setNum(tile_heap->GetScore());
    qp.drawText(QRect(0, 0, TILE_SIZE*6, TILE_SIZE*2), Qt::AlignCenter, score);

    field = fieldScene.addPixmap(field_pix);
    field->setPos(0, 0);

    next_fig_field = fieldScene.addPixmap(next_fig_pix);
    next_fig_field->setPos(FIELD_WIDTH + INFO_FIELD_WIDTH/2 - TILE_SIZE*2, INFO_FIELD_WIDTH/2 - TILE_SIZE*2);

    score_field = fieldScene.addPixmap(score_pix);
    score_field->setPos(FIELD_WIDTH + INFO_FIELD_WIDTH/2 - TILE_SIZE*3, INFO_FIELD_WIDTH/2 + TILE_SIZE*4);
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
