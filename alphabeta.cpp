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
        auto score=0;
        if(move.captured!=none){
            score = alphabeta::min(alpha,beta,depthleft,game);
        }else{
            score = alphabeta::min(alpha,beta,depthleft-1,game);
        }
        game->undo_move(&m);
        if( score >= beta ) return beta;   // fail hard beta-cutoff
        if( score > alpha ) {
            alpha = score;
        }
    }
    return alpha;
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
        auto score=0;
        if(move.captured!=none){
            score = alphabeta::max(alpha,beta,depthleft,game);
        }else{
            score = alphabeta::max(alpha,beta,depthleft-1,game);
        }
        game->undo_move(&m);
        if( score <= alpha ) return alpha;   // fail hard beta-cutoff
        if( score < beta ) {
            beta = score;
        }
    }

    return beta;
}

void alphabeta::find_best_move(GameState* game, Move* best_move){
    QVector<Move> moves;
    for(int i=0;i<16;++i){
        if(game->black[i]->in_game){
            game->black[i]->generate_moves(moves,game->b);
        }
    }

    int index_best_move =0;
    int i=0;
    int alpha=-10000,beta=10000;
    for(auto move: moves){
        Move m=move;
        game->make_move(&m);
        auto score = alphabeta::max(alpha,beta,1,game);//not working properly
        if(score<beta){
            beta = score;
            index_best_move = i;
        }
        game->undo_move(&m);
        ++i;
    }
    *best_move = moves[index_best_move];

}
