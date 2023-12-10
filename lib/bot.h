#if !defined(bot_H)
#define bot_H
#include "../include/boolean.h"
#include "board.h"

#define PLAYER1 1
#define PLAYER2 2
#define COMPUTER 3

#define PLAYER1SYMBOL "X"
#define PLAYER2SYMBOL "O" // Also used for bot/computer

/**
 * Board position.
 */
typedef struct
{
  int row, col;
} Move;

bool isMovesLeft(Board **tempBoard);

int evaluate(Board **tempBoard);

int minimax(Board **tempBoard, int depth, int maxDepth, bool isMax);

Move findBestMove(Board **tempBoard, int botDiff);

void playPvC(Board **board, Board **hintBoard, char *player, int whoseTurn, int botDiff);

#endif // bot_H
