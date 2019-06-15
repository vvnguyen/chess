#ifndef GAMEALGORITHM_H
#define GAMEALGORITHM_H

#include <QObject>
#include "chessboard.h"

class GameAlgorithm : public QObject
{
    Q_OBJECT
public:
    explicit GameAlgorithm(QObject *parent = nullptr);
    ChessBoard* board() const;

signals:
    void boardChanged(ChessBoard*);
public slots:
    virtual void newGame();
protected:
    virtual void setupBoard();
private:
    ChessBoard* m_board;
public:
    ChessBoard* board(){return m_board;}
protected:
    void setBoard(ChessBoard *board);
};

#endif // GAMEALGORITHM_H
