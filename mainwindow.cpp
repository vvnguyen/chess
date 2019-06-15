#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    m_view->setPiece('P', QIcon("F:/white_pawn.png")); // pawn
    m_view->setPiece('K', QIcon("F:/white_king.png")); // king
    m_view->setPiece('Q', QIcon("F:/white_queen.png")); //
    m_view->setPiece('R', QIcon("F:/white_rook.png")); // rook
    m_view->setPiece('N', QIcon("F:/white_knight.png")); // knight
    m_view->setPiece('B', QIcon("F:/white_bishop.png")); // bishop
    m_view->setPiece('p', QIcon("F:/black_pawn.png")); // pawn
    m_view->setPiece('k', QIcon("F:/black_king.png")); // king
    m_view->setPiece('q', QIcon("F:/black_queen.png")); // queen
    m_view->setPiece('r', QIcon("F:/black_rook.png")); // rook
    m_view->setPiece('n', QIcon("F:/black_knight.png")); // knight
    m_view->setPiece('b', QIcon("F:/black_bishop.png")); // bishop

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
        m_view->board()->movePiece(
             m_clickPoint.x(), m_clickPoint.y(),
            field.x(), field.y()
        );
    }
    m_clickPoint = QPoint();
    }
}
