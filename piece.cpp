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
            if((on/8)==1){//double move from rank 2
                auto field_double_up = on+16;
                if(board.fields[field_double_up]==nullptr){
                    Move m;
                    m.from = on;
                    m.to = field_double_up;
                    m.captured = 0;
                    m.promoted = 0;
                    moves.push_back(m);
                }
            }
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
            if((on/8)==6){
                auto field_double_down = on-16;
                if(board.fields[field_double_down]==nullptr){
                    m.from = on;
                    m.to = field_double_down;
                    m.captured = 0;
                    m.promoted = 0;
                    moves.push_back(m);
                }
            }
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

        if((on%8)!=7){
            auto field_right_down = on-9;
            auto piece_to_be_taken = board.fields[field_right_down];
            if(piece_to_be_taken!=nullptr){
                if(piece_to_be_taken->color==white){
                    Move m;
                    m.from = on;
                    m.to = field_right_down;
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
    int column = on%8;
    int row = on/8;

    //two left one down
    if((column>1)&&(row>0)){
        auto move_to = on -10;
        if(board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(board.fields[move_to]->color!=board.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two down one left
    if((column>0)&&(row>1)){
        auto move_to = on -17;
        if(board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(board.fields[move_to]->color!=board.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two left one up
    if((column>1)&&(row<7)){
        auto move_to = on+6;
        if(board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(board.fields[move_to]->color!=board.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //one left two up
    if((column>0)&&(row<6)){
        auto move_to = on+15;
        if(board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(board.fields[move_to]->color!=board.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two right one down
    if((column<6)&&(row>0)){
        auto move_to = on -6;
        if(board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(board.fields[move_to]->color!=board.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
    //one right two down
    if((column<7)&&(row>1)){
        auto move_to = on -15;
        if(board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(board.fields[move_to]->color!=board.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
}

void Bishop::generate_moves(QVector<Move>& moves, Board& board)
{
    int column = on%8;
    int row = on/8;

    //up right
    int column_to = column+1;
    int row_to = row+1;
    unsigned int move_to = on + 9;
    while(column_to<8 && row_to<8 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=9;
        ++column_to;
        ++row_to;
    }
    if(column_to<8 && row_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //up left
    column_to = column-1;
    row_to = row+1;
    move_to = on + 7;
    while(column_to>=0 && row_to<8 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=7;
        --column_to;
        ++row_to;
    }
    if(column_to>=0 && row_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down right
    column_to = column+1;
    row_to = row-1;
    move_to = on -7;
    while(column_to<8 && row_to>=0 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=7;
        ++column_to;
        --row_to;
    }
    if(column_to<8 && row_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down left
    column_to = column-1;
    row_to = row-1;
    move_to = on -9;
    while(column_to>=0 && row_to>=0 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=9;
        --column_to;
        --row_to;
    }
    if(column_to>=0 && row_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
}

void Rook::generate_moves(QVector<Move>& moves, Board& board)
{
    int column = on%8;
    int row = on/8;

    //up
    int column_to = column;
    int row_to = row+1;
    unsigned int move_to = on + 8;
    while(row_to<8 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=8;
        ++row_to;
    }
    if(row_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down
    move_to = on - 8;
    row_to = row-1;
    while(row_to>=0 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=8;
        --row_to;
    }
    if(row_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //left
    column_to = column-1;
    move_to = on-1;
    while(column_to>=0 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=1;
        --column_to;
    }
    if(column_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //right
    column_to = column+1;
    move_to = on+1;
    while(column_to<8 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=1;
        ++column_to;
    }
    if(column_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
}

void King::generate_moves(QVector<Move>& moves, Board& board)
{
    int column = on%8;
    int row = on/8;
    if(column>0){
        if(row>0){
            unsigned int move_to = on-9;
            if( board.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = 0;
                m.promoted = 0;
                moves.push_back(m);
            } else if(board.fields[move_to]->color!=board.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
            }
        }
    }
    if(row>0){
        unsigned int move_to = on-8;
        if( board.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else if(board.fields[move_to]->color!=board.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
        }
    }
    if(row>0){
        if(column<7){
            unsigned int move_to = on-7;
            if( board.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = 0;
                m.promoted = 0;
                moves.push_back(m);
            } else if(board.fields[move_to]->color!=board.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
            }
        }
    }
    if(column<7){
        unsigned int move_to = on+1;
        if( board.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else if(board.fields[move_to]->color!=board.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
        }
    }
    if(column>0){
        unsigned int move_to = on-1;
        if( board.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else if(board.fields[move_to]->color!=board.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
        }
    }
    if(row<7){
        unsigned int move_to = on+8;
        if( board.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
        } else if(board.fields[move_to]->color!=board.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
        }
    }
    if(row<7){
        if(column>0){
            unsigned int move_to = on+7;
            if( board.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = 0;
                m.promoted = 0;
                moves.push_back(m);
            } else if(board.fields[move_to]->color!=board.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
            }
        }
    }
    if(row<7){
        if(column<7){
            unsigned int move_to = on+9;
            if( board.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = 0;
                m.promoted = 0;
                moves.push_back(m);
            } else if(board.fields[move_to]->color!=board.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = board.fields[move_to]->value;
                m.promoted = 0;
            }
        }
    }
}

void Queen::generate_moves(QVector<Move>& moves, Board& board)
{
    int column = on%8;
    int row = on/8;

    //up right
    int column_to = column+1;
    int row_to = row+1;
    unsigned int move_to = on + 9;
    while(column_to<8 && row_to<8 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=9;
        ++column_to;
        ++row_to;
    }
    if(column_to<8 && row_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //up left
    column_to = column-1;
    row_to = row+1;
    move_to = on + 7;
    while(column_to>=0 && row_to<8 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=7;
        --column_to;
        ++row_to;
    }
    if(column_to>=0 && row_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down right
    column_to = column+1;
    row_to = row-1;
    move_to = on -7;
    while(column_to<8 && row_to>=0 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=7;
        ++column_to;
        --row_to;
    }
    if(column_to<8 && row_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down left
    column_to = column-1;
    row_to = row-1;
    move_to = on -9;
    while(column_to>=0 && row_to>=0 && board.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = 0;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=9;
        --column_to;
        --row_to;
    }
    if(column_to>=0 && row_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = board.fields[move_to]->value;
        m.promoted = 0;
        moves.push_back(m);
    }

    column_to = column;
    row_to = row+1;
    move_to = on + 8;
        while(row_to<8 && board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
            move_to+=8;
            ++row_to;
        }
        if(row_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
            moves.push_back(m);
        }
        //down
        move_to = on - 8;
        row_to = row-1;
        while(row_to>=0 && board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
            move_to-=8;
            --row_to;
        }
        if(row_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
            moves.push_back(m);
        }
        //left
        column_to = column-1;
        move_to = on-1;
        while(column_to>=0 && board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
            move_to-=1;
            --column_to;
        }
        if(column_to>=0 && board.fields[move_to]->color!=board.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
            moves.push_back(m);
        }
        //right
        column_to = column+1;
        move_to = on+1;
        while(column_to<8 && board.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = 0;
            m.promoted = 0;
            moves.push_back(m);
            move_to+=1;
            ++column_to;
        }
        if(column_to<8 && board.fields[move_to]->color!=board.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = board.fields[move_to]->value;
            m.promoted = 0;
            moves.push_back(m);
        }
}

