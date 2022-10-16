#ifndef PIECE_H
#define PIECE_H
#include <QVector>

typedef unsigned int position_t;
const unsigned int none = 31;

struct Move{
    unsigned int from:8;
    unsigned int to:8;
    unsigned int captured:5;
    unsigned int moved:5;
    unsigned int promoted:5;
};

struct Board;

typedef
struct Piece
{
    enum color_t{black=0,white=1};
    unsigned int id;
    position_t on;
    color_t color;
    bool in_game;
    int value;
    virtual void generate_moves(QVector<Move>& moves)=0;
    virtual int mobility_value( position_t position)=0;
    virtual ~Piece()=0;
}Piece;

typedef
struct Board
{
    Piece* fields[64];
}Board;

typedef
struct GameState{
    Board b;
    bool current_side;
    QVector<Piece*> white;
    QVector<Piece*> black;
    QVector<Move> done;
    void make_move(struct Move* m);
    void undo_move(struct Move* m);
private:
    void init();
    void clean();
public:
    GameState() {init();}
    ~GameState(){clean();}
}GameState;

struct Pawn: Piece
{
    static const int pawn_value = 10;
    static const int white_pawn_mobility_value[64];
    static const int black_pawn_mobility_value[64];
    void generate_moves(QVector<Move>& moves);
    int mobility_value( position_t position);
};

struct Knight: Piece
{
    static const int knight_value = 30;
    static const int knight_mobility_value[64];
    void generate_moves(QVector<Move>& moves);
    int mobility_value( position_t position);
};

struct Bishop: Piece
{
    static const int bishop_value = 30;
    static const int bishop_mobility_value[64];
    void generate_moves(QVector<Move>& moves);
    int mobility_value( position_t position);
};

struct Rook: Piece
{
    static const int rook_value = 50;
    void generate_moves(QVector<Move>& moves);
    int mobility_value( position_t position);
};

struct King: Piece
{
    static const int king_value = 100;
    void generate_moves(QVector<Move>& moves);
    bool is_safe(Board& board);
    int mobility_value( position_t position);
};

struct Queen: Piece
{
    static const int queen_value = 90;
    void generate_moves(QVector<Move>& moves);
    int mobility_value( position_t position);
};

extern GameState g;

#endif // PIECE_H
