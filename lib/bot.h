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

/**
 * Procedure for manage scoring mechanism.
 *
 * base score:
 * - bot (easy)   = +5 point
 * - bot (medium) = +10 point
 * - bot (hard)   = +20 point
 * - human        = +20 point
 *
 * Scoring system based on board size:
 * - 3x3: base score muliply by 1 (*1)
 * - 5x5: base score muliply by 2 (*2)
 * - 7x7: base score muliply by 3 (*3)
 */
void setScore(int mode, int bot, int board, char *player, bool isWin);

void playPvC(Board **board, Board **hintBoard, char *player, int whoseTurn, int botDiff);

#endif // bot_H
