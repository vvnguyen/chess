#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QWidget>
#include <QPointer>
#include <QMap>
#include <QIcon>
#include "chessboard.h"

class ChessView : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QSize fieldSize READ fieldSize WRITE setFildSize NOTIFY fieldSizeChanged)
public:
    explicit ChessView(QWidget *parent = nullptr);
    void setBoard(ChessBoard *board);
    void setFieldSize(QSize fieldSize);
    QSize sizeHint() const;
    QRect fieldRect(int column, int rank) const;
    QPoint fieldAt(const QPoint &pt) const;
    void mouseReleaseEvent(QMouseEvent *event);
public:
    void setPiece(char type, const QIcon &icon);
    QIcon piece(char type) const;
    void drawPiece(QPainter *painter, int column, int rank);
private:
    QMap<char,QIcon> m_pieces;

protected:
    void drawRank(QPainter *painter, int rank);
    void drawColumn(QPainter *painter, int column);
    void paintEvent(QPaintEvent *event);
    void drawField(QPainter *painter, int column, int rank);
signals:
    void clicked(const QPoint&);
    void fieldSizeChanged(QSize fieldSize);

public slots:

private:
QPointer<ChessBoard> m_board;
QSize m_fieldSize;

public:
ChessBoard *board() const { return m_board; }
    QSize fieldSize() const
    {
        return m_fieldSize;
    }
};

#endif // CHESSVIEW_H
