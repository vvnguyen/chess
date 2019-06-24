#include "evaluate.h"

int evaluate(GameState* game){
    int material_value =0;
    for(int i=0;i<16;++i){
        if(game->white[i]->on){
            material_value += game->white[i]->value;
        }
    }
    for(int j=0;j<16;++j){
        if(game->black[j]->on){
            material_value -= game->black[j]->value;
        }
    }

    return material_value;
}
