#if !defined(game_H)
#define game_H
#include "bot.h"

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
 * Procedure for rematch the game.
 */
void rematch(bool err, int mode, int bot, int board, char *player1, char *player2);

void playPvP(Board **board, Board **hintBoard, char *player1, char *player2, int whoseTurn);

void tictactoe(int mode, int bot, int board, char *player1, char *player2);

#endif // game_H
