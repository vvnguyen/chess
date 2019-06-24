#include "alphabeta.h"
#include "evaluate.h"
#include <QVector>

int alphabeta::max(int alpha, int beta, int depthleft, GameState* game){
    if(depthleft==0) return evaluate(game);

    QVector<Move> moves;
    for(int i=0;i<16;++i){
        if(game->white[i]->in_game){
            game->white[i]->generate_moves(moves,game->b);
        }
    }

    for (auto move : moves){
        Move m=move;
        game->make_move(&m);
        auto score = alphabeta::min(alpha,beta,depthleft-1,game);
        game->undo_move(&m);
        if( score >= beta ) return beta;   // fail hard beta-cutoff
        if( score > alpha ) {
            alpha = score;
        }
    }
    return 0;
}

int alphabeta::min(int alpha, int beta,int depthleft, GameState* game){
    if(depthleft==0) return evaluate(game);

    QVector<Move> moves;
    for(int i=0;i<16;++i){
        if(game->black[i]->in_game){
            game->black[i]->generate_moves(moves,game->b);
        }
    }

    for (auto move : moves){
        Move m=move;
        game->make_move(&m);
        auto score = alphabeta::min(alpha,beta,depthleft-1,game);
        game->undo_move(&m);
        if( score < alpha ) return alpha;   // fail hard beta-cutoff
        if( score < beta ) {
            beta = score;
        }
    }

    return 0;
}
