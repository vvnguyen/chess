#include "evaluate.h"

int evaluate(GameState* game){
    int material_value =0;
    for(int i=0;i<16;++i){
        if(game->white[i]->in_game){
            material_value += game->white[i]->value;
        }
    }
    for(int j=0;j<16;++j){
        if(game->black[j]->in_game){
            material_value -= game->black[j]->value;
        }
    }

    int position_value=0;
    for(int i=0;i<16;++i){
        if(game->white[i]->in_game){
            position_value += game->white[i]->mobility_value(game->white[i]->on);
        }
    }
    for(int j=0;j<16;++j){
        if(game->black[j]->in_game){
            position_value -= game->black[j]->mobility_value(game->black[j]->on);
        }
    }

    return material_value+position_value;
}
