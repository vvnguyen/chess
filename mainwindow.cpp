#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "piece.h"
#include "alphabeta.h"
#include <QLayout>
#include <QIcon>
#include <QMap>
#include <QDebug>
#include <QDir>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_view = new ChessView;
    m_algorithm = new GameAlgorithm(this);
    m_algorithm->newGame();
    m_view->setBoard(m_algorithm->board());
    setCentralWidget(m_view);
    m_view->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_view->setFieldSize(QSize(50,50));
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    m_view->setPiece('P', QIcon(":/white_pawn.png")); // pawn
    m_view->setPiece('K', QIcon(":/white_king.png")); // king
    m_view->setPiece('Q', QIcon(":/white_queen.png")); //
    m_view->setPiece('R', QIcon(":/white_rook.png")); // rook
    m_view->setPiece('N', QIcon(":/white_knight.png")); // knight
    m_view->setPiece('B', QIcon(":/white_bishop.png")); // bishop
    m_view->setPiece('p', QIcon(":/black_pawn.png")); // pawn
    m_view->setPiece('k', QIcon(":/black_king.png")); // king
    m_view->setPiece('q', QIcon(":/black_queen.png")); // queen
    m_view->setPiece('r', QIcon(":/black_rook.png")); // rook
    m_view->setPiece('n', QIcon(":/black_knight.png")); // knight
    m_view->setPiece('b', QIcon(":/black_bishop.png")); // bishop

    connect(m_view, SIGNAL(clicked(QPoint)),
    this, SLOT(viewClicked(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::viewClicked(const QPoint &field)
{
    if(m_clickPoint.isNull()) {
        m_clickPoint = field;
    } else {
        if(field != m_clickPoint) {
            //Move white_move;
            //white_move.from = m_clickPoint.x()-1+(m_clickPoint.y()-1)*8;
            //white_move.to = field.x() -1 + (field.y()-1)*8;
            //this->g.make_move(&white_move);
            m_view->board()->movePiece(
                 m_clickPoint.x(), m_clickPoint.y(),
                field.x(), field.y()
            );

            //generate black moves
           Move black_move;
           alphabeta::find_best_move(&g,&black_move);
           this->g.make_move(&black_move);
           m_view->board()->movePiece(black_move.from%8+1,black_move.from/8+1,black_move.to%8+1,black_move.to/8+1);
        }
        m_clickPoint = QPoint();
    }
}
