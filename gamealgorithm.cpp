#include "gamealgorithm.h"

GameAlgorithm::GameAlgorithm(QObject *parent) : QObject(parent)
{
    m_board = nullptr;
}

void GameAlgorithm::setBoard(ChessBoard *board){
    if(m_board==board) return;
    if(m_board)delete m_board;
    m_board = board;
    emit boardChanged(m_board);
}

void GameAlgorithm::setupBoard()
{
    setBoard(new ChessBoard(8,8, this));
}

void GameAlgorithm::newGame(){
    setupBoard();
    board()->setFen(
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
    );

}
