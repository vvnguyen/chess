#ifndef ALPHABETA_H
#define ALPHABETA_H
#include "piece.h"

namespace alphabeta{

int max(int alpha, int beta, int depthleft, GameState* game);
int min(int alpha, int beta, int depthleft, GameState* game);

}

#endif // ALPHABETA_H
