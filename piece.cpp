#include "piece.h"

Piece::~Piece(){};

const int Pawn::white_pawn_mobility_value[] = { 1,1,1,1,1,1,1,1,
                                                1,1,1,1,1,1,1,1,
                                                1,1,2,2,2,2,1,1,
                                                1,1,2,2,2,2,1,1,
                                                2,2,2,2,2,2,2,2,
                                                2,2,2,2,2,2,2,2,
                                                3,3,3,3,3,3,3,3,
                                                3,3,3,3,3,3,3,3};

const int Pawn::black_pawn_mobility_value[] = { 3,3,3,3,3,3,3,3,
                                                3,3,3,3,3,3,3,3,
                                                2,2,2,2,2,2,2,2,
                                                2,2,2,2,2,2,2,2,
                                                1,1,2,2,2,2,1,1,
                                                1,1,2,2,2,2,1,1,
                                                1,1,1,1,1,1,1,1,
                                                1,1,1,1,1,1,1,1};

const int Knight::knight_mobility_value[] = { 1,1,1,1,1,1,1,1,
                                              1,2,2,2,2,2,2,1,
                                              1,2,2,3,3,2,2,1,
                                              1,2,3,3,3,3,2,1,
                                              1,2,3,3,3,3,2,1,
                                              1,2,2,3,3,2,2,1,
                                              1,2,2,2,2,2,2,1,
                                              1,1,1,1,1,1,1,1};

const int Bishop::bishop_mobility_value[] = { 1,1,1,1,1,1,1,1,
                                              1,2,2,2,2,2,2,1,
                                              1,2,2,3,3,2,2,1,
                                              1,2,3,3,3,3,2,1,
                                              1,2,3,3,3,3,2,1,
                                              1,2,2,3,3,2,2,1,
                                              1,2,2,2,2,2,2,1,
                                              1,1,1,1,1,1,1,1};

int Pawn::mobility_value(position_t position){
    if(Pawn::color==white){
        return white_pawn_mobility_value[position];
    } else {
        return black_pawn_mobility_value[position];
    }
}

int Knight::mobility_value( position_t position) {
    return knight_mobility_value[position];
}

int Bishop::mobility_value( position_t position) {
    return bishop_mobility_value[position];
}

int Rook::mobility_value( position_t position) {
    return 1;
}

int Queen::mobility_value( position_t position){
    return 1;
}

int King::mobility_value( position_t position) {
    return 1;
}

void Pawn::generate_moves(QVector<Move>& moves)
{
    if(color==white){
        auto field_up = on+8;
        if(on<56){
            if(g.b.fields[field_up]==nullptr){
                Move m;
                m.from = on;
                m.to = field_up;
                m.captured = none;
                m.promoted = 0;
                moves.push_back(m);
                if((on/8)==1){//double move from rank 2
                    auto field_double_up = on+16;
                    if(g.b.fields[field_double_up]==nullptr){
                        Move m;
                        m.from = on;
                        m.to = field_double_up;
                        m.captured = none;
                        m.promoted = 0;
                        moves.push_back(m);
                    }
                }
            }

            //left up
            if(on%8){
                auto field_left_up = on+7;
                auto piece_to_be_taken = g.b.fields[field_left_up];
                if(piece_to_be_taken!=nullptr){
                    if(piece_to_be_taken->color==black){
                        Move m;
                        m.from = on;
                        m.to = field_left_up;
                        m.captured = piece_to_be_taken->id;
                        m.promoted = 0;
                        moves.push_back(m);
                    }
                }
            }
            //right up
            if((on%8)!=7){
                auto field_right_up = on+9;
                auto piece_to_be_taken = g.b.fields[field_right_up];
                if(piece_to_be_taken!=nullptr){
                    if(piece_to_be_taken->color==black){
                        Move m;
                        m.from = on;
                        m.to = field_right_up;
                        m.captured = piece_to_be_taken->id;
                        m.promoted = 0;
                        moves.push_back(m);
                    }
                }
            }
        }
    }else{ //black pawn
        auto field_down = on-8;
        if(on>=8){
            if(g.b.fields[field_down]==nullptr){
                Move m;
                m.from = on;
                m.to = field_down;
                m.captured = none;
                m.promoted = 0;
                moves.push_back(m);
                if((on/8)==6){
                    auto field_double_down = on-16;
                    if(g.b.fields[field_double_down]==nullptr){
                        m.from = on;
                        m.to = field_double_down;
                        m.captured = none;
                        m.promoted = 0;
                        moves.push_back(m);
                    }
                }
            }
        }
        //left down
        if((on%8)!=7){
            if(on>=8){
                auto field_left_down = on-7;
                auto piece_to_be_taken = g.b.fields[field_left_down];
                if(piece_to_be_taken!=nullptr){
                    if(piece_to_be_taken->color==white){
                        Move m;
                        m.from = on;
                        m.to = field_left_down;
                        m.captured = piece_to_be_taken->id;
                        m.promoted = 0;
                        moves.push_back(m);
                    }
                }
            }

        }
        if(on%8){
            if(on>=9){
                auto field_right_down = on-9;
                auto piece_to_be_taken = g.b.fields[field_right_down];
                if(piece_to_be_taken!=nullptr){
                    if(piece_to_be_taken->color==white){
                        Move m;
                        m.from = on;
                        m.to = field_right_down;
                        m.captured = piece_to_be_taken->id;
                        m.promoted = 0;
                        moves.push_back(m);
                    }
                }
            }
        }
    }
}

void Knight::generate_moves(QVector<Move>& moves)
{
    int column = on%8;
    int row = on/8;

    //two left one down
    if((column>1)&&(row>0)){
        auto move_to = on -10;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two down one left
    if((column>0)&&(row>1)){
        auto move_to = on -17;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two left one up
    if((column>1)&&(row<7)){
        auto move_to = on+6;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //one left two up
    if((column>0)&&(row<6)){
        auto move_to = on+15;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two right one down
    if((column<6)&&(row>0)){
        auto move_to = on -6;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
    //one right two down
    if((column<7)&&(row>1)){
        auto move_to = on -15;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //two right one up
    if((column<6)&&(row<7)){
        auto move_to = on +10;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }

    //one right two up
    if((column<6)&&(row<6)){
        auto move_to = on +17;
        if(g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else {
            if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                //opposite piece
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
}

void Bishop::generate_moves(QVector<Move>& moves)
{
    int column = on%8;
    int row = on/8;

    //up right
    int column_to = column+1;
    int row_to = row+1;
    unsigned int move_to = on + 9;
    while(column_to<8 && row_to<8 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=9;
        ++column_to;
        ++row_to;
    }
    if(column_to<8 && row_to<8 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //up left
    column_to = column-1;
    row_to = row+1;
    move_to = on + 7;
    while(column_to>=0 && row_to<8 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=7;
        --column_to;
        ++row_to;
    }
    if(column_to>=0 && row_to<8 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down right
    column_to = column+1;
    row_to = row-1;
    move_to = on -7;
    while(column_to<8 && row_to>=0 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=7;
        ++column_to;
        --row_to;
    }
    if(column_to<8 && row_to>=0 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down left
    column_to = column-1;
    row_to = row-1;
    move_to = on -9;
    while(column_to>=0 && row_to>=0 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=9;
        --column_to;
        --row_to;
    }
    if(column_to>=0 && row_to>=0 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
}

void Rook::generate_moves(QVector<Move>& moves)
{
    int column = on%8;
    int row = on/8;

    //up
    int column_to = column;
    int row_to = row+1;
    unsigned int move_to = on + 8;
    while(row_to<8 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=8;
        ++row_to;
    }
    if(row_to<8 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down
    move_to = on - 8;
    row_to = row-1;
    while(row_to>=0 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=8;
        --row_to;
    }
    if(row_to>=0 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //left
    column_to = column-1;
    move_to = on-1;
    while(column_to>=0 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=1;
        --column_to;
    }
    if(column_to>=0 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //right
    column_to = column+1;
    move_to = on+1;
    while(column_to<8 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=1;
        ++column_to;
    }
    if(column_to<8 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
}

void King::generate_moves(QVector<Move>& moves)
{
    int column = on%8;
    int row = on/8;
    if(column>0){
        if(row>0){
            unsigned int move_to = on-9;
            if( g.b.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = none;
                m.promoted = 0;
                moves.push_back(m);
            } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
    if(row>0){
        unsigned int move_to = on-8;
        if( g.b.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
    }
    if(row>0){
        if(column<7){
            unsigned int move_to = on-7;
            if( g.b.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = none;
                m.promoted = 0;
                moves.push_back(m);
            } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
    if(column<7){
        unsigned int move_to = on+1;
        if( g.b.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
    }
    if(column>0){
        unsigned int move_to = on-1;
        if( g.b.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
    }
    if(row<7){
        unsigned int move_to = on+8;
        if( g.b.fields[move_to]==nullptr ){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
        } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
    }
    if(row<7){
        if(column>0){
            unsigned int move_to = on+7;
            if( g.b.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = none;
                m.promoted = 0;
                moves.push_back(m);
            } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
    if(row<7){
        if(column<7){
            unsigned int move_to = on+9;
            if( g.b.fields[move_to]==nullptr ){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = none;
                m.promoted = 0;
                moves.push_back(m);
            } else if(g.b.fields[move_to]->color!=g.b.fields[on]->color){
                Move m;
                m.from = on;
                m.to = move_to;
                m.captured = g.b.fields[move_to]->id;
                m.promoted = 0;
                moves.push_back(m);
            }
        }
    }
}

void Queen::generate_moves(QVector<Move>& moves)
{
    int column = on%8;
    int row = on/8;

    //up right
    int column_to = column+1;
    int row_to = row+1;
    unsigned int move_to = on + 9;
    while(column_to<8 && row_to<8 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=9;
        ++column_to;
        ++row_to;
    }
    if(column_to<8 && row_to<8 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //up left
    column_to = column-1;
    row_to = row+1;
    move_to = on + 7;
    while(column_to>=0 && row_to<8 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to+=7;
        --column_to;
        ++row_to;
    }
    if(column_to>=0 && row_to<8 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down right
    column_to = column+1;
    row_to = row-1;
    move_to = on -7;
    while(column_to<8 && row_to>=0 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=7;
        ++column_to;
        --row_to;
    }
    if(column_to<8 && row_to>=0 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }
    //down left
    column_to = column-1;
    row_to = row-1;
    move_to = on -9;
    while(column_to>=0 && row_to>=0 && g.b.fields[move_to]==nullptr){
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = none;
        m.promoted = 0;
        moves.push_back(m);
        move_to-=9;
        --column_to;
        --row_to;
    }
    if(column_to>=0 && row_to>=0 && g.b.fields[move_to]->color!=g.b.fields[on]->color){
        //opposite piece
        Move m;
        m.from = on;
        m.to = move_to;
        m.captured = g.b.fields[move_to]->id;
        m.promoted = 0;
        moves.push_back(m);
    }

    column_to = column;
    row_to = row+1;
    move_to = on + 8;
        while(row_to<8 && g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
            move_to+=8;
            ++row_to;
        }
        if(row_to<8 && g.b.fields[move_to] && g.b.fields[move_to]->color!=g.b.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
        //down
        move_to = on - 8;
        row_to = row-1;
        while(row_to>=0 && g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
            move_to-=8;
            --row_to;
        }
        if(row_to>=0 && g.b.fields[move_to] && g.b.fields[move_to]->color!=g.b.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
        //left
        column_to = column-1;
        move_to = on-1;
        row_to = row;
        while(column_to>=0 && g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
            move_to-=1;
            --column_to;
        }
        if(column_to>=0 && g.b.fields[move_to] && g.b.fields[move_to]->color!=g.b.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
        //right
        column_to = column+1;
        move_to = on+1;
        while(column_to<8 && g.b.fields[move_to]==nullptr){
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = none;
            m.promoted = 0;
            moves.push_back(m);
            move_to+=1;
            ++column_to;
        }
        if(column_to<8 && g.b.fields[move_to] && g.b.fields[move_to]->color!=g.b.fields[on]->color){
            //opposite piece
            Move m;
            m.from = on;
            m.to = move_to;
            m.captured = g.b.fields[move_to]->id;
            m.promoted = 0;
            moves.push_back(m);
        }
}
/*
int Pawn::mobility_value(struct Board& b, position_t position) {
    int value =0;
    if(this->color==white){

    } else {

    }
    return value;
}*/

void GameState::make_move(Move* m){
    if(m->captured!=none){
        this->b.fields[m->to]->in_game=false;
    }
    if(this->b.fields[m->from]==nullptr){
        return;
    }
    this->b.fields[m->to]=this->b.fields[m->from];
    this->b.fields[m->from]=nullptr;
    this->b.fields[m->to]->on=m->to;
    done.push_back(*m);
}

void GameState::undo_move(Move* m){
    if(b.fields[m->to]==nullptr){
        return;
    }
    auto c = this->b.fields[m->to]->color;
    this->b.fields[m->from] = this->b.fields[m->to];
    this->b.fields[m->from]->on = m->from;
    this->b.fields[m->to] = nullptr;
    if(m->captured!=none){
        if(c==Piece::white){
            black[m->captured]->in_game=true;
            this->b.fields[m->to] = black[m->captured];
        }else {
            white[m->captured]->in_game=true;
            this->b.fields[m->to] = white[m->captured];
        }
    }
    done.pop_back();
}

void GameState::init(){
    white.resize(16);
    black.resize(16);
    white[0] = new Pawn(); white[0]->on = 11; b.fields[11]=white[0]; white[0]->value=10;
    white[1] = new Pawn(); white[1]->on = 12; b.fields[12]=white[1]; white[1]->value=10;
    white[2] = new Pawn(); white[2]->on = 10; b.fields[10]=white[2]; white[2]->value=10;
    white[3] = new Pawn(); white[3]->on = 13; b.fields[13]=white[3]; white[3]->value=10;
    white[6] = new Pawn(); white[6]->on = 9; b.fields[9]=white[6]; white[6]->value=10;
    white[7] = new Pawn(); white[7]->on = 14; b.fields[14]=white[7]; white[7]->value=10;
    white[10] = new Pawn(); white[10]->on = 8; b.fields[8]=white[10]; white[10]->value=10;
    white[11] = new Pawn(); white[11]->on = 15; b.fields[15]=white[11]; white[11]->value=10;

    white[4] = new Knight(); white[4]->on = 1; b.fields[1]=white[4]; white[4]->value=30;
    white[5] = new Knight(); white[5]->on = 6; b.fields[6]=white[5]; white[5]->value=30;
    white[8] = new Bishop(); white[8]->on = 2; b.fields[2]=white[8]; white[8]->value=30;
    white[9] = new Bishop(); white[9]->on = 5; b.fields[5]=white[9]; white[9]->value=30;
    white[12] = new Rook(); white[12]->on = 0; b.fields[0]=white[12]; white[12]->value=50;
    white[13] = new Rook(); white[13]->on = 7; b.fields[7]=white[13];  white[13]->value=50;
    white[14] = new Queen(); white[14]->on = 3; b.fields[3]=white[14]; white[14]->value=90;
    white[15] = new King(); white[15]->on = 4; b.fields[4]=white[15]; white[15]->value=100;

    for(int i=0;i<16;++i){
        white[i]->in_game=true;
        white[i]->color=Piece::white;
        white[i]->id = i;
    }

    for(int field =16;field<48;++field){
        b.fields[field] = nullptr;//empty fields in middle
    }
    black[0] = new Pawn(); black[0]->on = 51; b.fields[51]=black[0]; black[0]->value=10;
    black[1] = new Pawn(); black[1]->on = 52; b.fields[52]=black[1]; black[1]->value=10;
    black[2] = new Pawn(); black[2]->on = 50; b.fields[50]=black[2]; black[2]->value=10;
    black[3] = new Pawn(); black[3]->on = 53; b.fields[53]=black[3]; black[3]->value=10;
    black[6] = new Pawn(); black[6]->on = 49; b.fields[49]=black[6]; black[6]->value=10;
    black[7] = new Pawn(); black[7]->on = 54; b.fields[54]=black[7]; black[7]->value=10;
    black[10] = new Pawn(); black[10]->on = 48; b.fields[48]=black[10]; black[10]->value=10;
    black[11] = new Pawn(); black[11]->on = 55; b.fields[55]=black[11]; black[11]->value=10;
    black[4] = new Knight(); black[4]->on = 57; b.fields[57]=black[4]; black[4]->value=30;
    black[5] = new Knight(); black[5]->on = 62; b.fields[62]=black[5]; black[5]->value=30;
    black[8] = new Bishop(); black[8]->on = 58; b.fields[58]=black[8]; black[8]->value=30;
    black[9] = new Bishop(); black[9]->on = 61; b.fields[61]=black[9]; black[9]->value=30;
    black[12] = new Rook(); black[12]->on = 56; b.fields[56]=black[12]; black[12]->value=50;
    black[13] = new Rook(); black[13]->on = 63; b.fields[63]=black[13]; black[13]->value=50;
    black[14] = new Queen(); black[14]->on = 59; b.fields[59]=black[14]; black[14]->value=90;
    black[15] = new King(); black[15]->on = 60; b.fields[60]=black[15]; black[15]->value=100;
    for(int i=0;i<16;++i){
        black[i]->in_game=true;
        black[i]->color=Piece::black;
        black[i]->id=i;
    }

    current_side = Piece::white;
}
void GameState::clean(){
    for(int i=0;i<16;++i){
        delete white[i];
        delete black[i];
    }
}

GameState g;
