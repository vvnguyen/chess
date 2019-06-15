#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chessview.h"
#include "gamealgorithm.h"
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    ChessView *m_view;
    GameAlgorithm *m_algorithm;
    QPoint m_clickPoint;

public slots:
    void viewClicked(const QPoint &);
};

#endif // MAINWINDOW_H
