#if !defined(bot_H)
#define bot_H
#include "../include/boolean.h"
#include "board.h"

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

Move findBestMove(Board **tempBoard);

/**
 * Procedure for randomize bot's movement.
 */
void randomizeMove(int moves[]);

void playPvC(Board **board, Board **hintBoard, char *player, int whoseTurn, int botDiff);

#endif // bot_H
