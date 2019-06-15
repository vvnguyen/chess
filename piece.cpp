#include "piece.h"

Piece::~Piece(){};

void Pawn::generate_moves(QVector<Move>& moves, Board& board)
{
    if(color==white){
        auto field_up = on+8;
        if(board.fields[field_up]==nullptr){
            Move m;
            m.from = on;
            m.to = field_up;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        }
        //left up
        if(on%8){
            auto field_left_up = on+7;
            auto piece_to_be_taken = board.fields[field_left_up];
            if(piece_to_be_taken!=nullptr){
                if(piece_to_be_taken->color==black){
                    Move m;
                    m.from = on;
                    m.to = field_left_up;
                    m.captured = piece_to_be_taken->value;
                    m.promoted = 0;
                    moves.push_back(m);
                }
            }
        }
        //right up
        if((on%8)!=7){
            auto field_right_up = on+9;
            auto piece_to_be_taken = board.fields[field_right_up];
            if(piece_to_be_taken!=nullptr){
                if(piece_to_be_taken->color==black){
                    Move m;
                    m.from = on;
                    m.to = field_right_up;
                    m.captured = piece_to_be_taken->value;
                    m.promoted = 0;
                    moves.push_back(m);
                }
            }
        }
    }else{ //black pawn
        auto field_down = on-8;
        if(board.fields[field_down]==nullptr){
            Move m;
            m.from = on;
            m.to = field_down;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        }
        //left down
        if(on%8){
            auto field_left_down = on-7;
            auto piece_to_be_taken = board.fields[field_left_down];
            if(piece_to_be_taken!=nullptr){
                if(piece_to_be_taken->color==white){
                    Move m;
                    m.from = on;
                    m.to = field_left_down;
                    m.captured = piece_to_be_taken->value;
                    m.promoted = 0;
                    moves.push_back(m);
                }
            }
        }
    }
}

void Knight::generate_moves(QVector<Move>& moves, Board& board)
{

}

void Bishop::generate_moves(QVector<Move>& moves, Board& board)
{

}

void Rook::generate_moves(QVector<Move>& moves, Board& board)
{

}

void King::generate_moves(QVector<Move>& moves, Board& board)
{

}

void Queen::generate_moves(QVector<Move>& moves, Board& board)
{

}
