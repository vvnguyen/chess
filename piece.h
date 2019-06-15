#ifndef PIECE_H
#define PIECE_H
#include <QVector>

typedef unsigned int position_t;

struct Move{
    unsigned int from:8;
    unsigned int to:8;
    unsigned int captured:6;
    unsigned int promoted:6;
};

struct Board;

typedef
struct Piece
{
    enum color_t{black=0,white=1};
    unsigned int value;
    position_t on;
    color_t color;
    virtual void generate_moves(QVector<Move>& moves, Board& board)=0;
    virtual ~Piece()=0;
}Piece;

typedef
struct Board
{
    Piece* fields[64];
}Board;

struct Pawn: Piece
{
    void generate_moves(QVector<Move>& moves, Board& board);
};

struct Knight: Piece
{
    void generate_moves(QVector<Move>& moves, Board& board);
};

struct Bishop: Piece
{
    void generate_moves(QVector<Move>& moves, Board& board);
};

struct Rook: Piece
{
    void generate_moves(QVector<Move>& moves, Board& board);
};

struct King: Piece
{
    void generate_moves(QVector<Move>& moves, Board& board);
};

struct Queen: Piece
{
    void generate_moves(QVector<Move>& moves, Board& board);
};

#endif // PIECE_H
