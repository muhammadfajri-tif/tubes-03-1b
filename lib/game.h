#if !defined(game_H)
#define game_H
#include "../include/boolean.h"
#include "board.h"

#define PLAYER1 1
#define PLAYER2 2
#define COMPUTER 3

#define PLAYER1SYMBOL "X"
#define PLAYER2SYMBOL "O" // Also used for bot/computer

bool rowCrossed(Board **board);

bool colCrossed(Board **board);

bool diagCrossed(Board **board);

bool gameOver(Board **board);

/**
 * Procedure for determine which player wins the game.
 */
void declareWinner(int whoseTurn, char *playername);

/**
 * Procedure for input and validate player's username.
 */
void inputUsername(char *username);

/**
 * Procedure for input/fill the game board.
 */
void inputMove(int *move, char *playername);

/**
 * Procedure for randomize bot's movement.
 */
void randomizeMove(int moves[]);

void playPvP(Board **board, Board **hintBoard, char *player1, char *player2, int whoseTurn);

void tictactoe(int mode, int bot, int board, char *player1, char *player2);

#endif // game_H
