#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QVector>

class ChessBoard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int ranks READ ranks NOTIFY ranksChanged)
    Q_PROPERTY(int columns READ columns NOTIFY columnsChanged)
public:
    explicit ChessBoard(QObject *parent = nullptr);
    ChessBoard(int x, int y, QObject *parent);
    int ranks() const {return m_ranks;}
    int columns() const {return m_columns;}

    char data(int column, int rank) const;
    void setData(int column, int rank, char value);
    void movePiece(int fromColumn, int fromRank, int tooColumn, int tooRank);

    void setFen(const QString& fen);
signals:
    void ranksChanged(int newRank);
    void columnsChanged(int newColumns);
    void dataChanged(int column,int rank);
    void boardReset();
public slots:

protected:
    void setRanks(int newRanks);
    void setColumns(int newColumns);
    void initBoard();
private:
    int m_ranks;
    int m_columns;
    QVector<char> m_boardData;
    bool setDataInternal(int column, int rank, char value);
};

#endif // CHESSBOARD_H
