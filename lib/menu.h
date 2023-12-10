#if !defined(menu_H)
#define menu_H
#include "../include/boolean.h"

/**
 * Procedure for setting game mode whether it's player vs player OR player vs computer.
 */
void selectGameMode(bool err, int *opsiMode);

/**
 * Procedure for setting computer/bot difficulty.
 */
void selectBot(bool err, int *opsiBot);

/**
 * Procedure for setting board size whether it's 3x3, 5x5, OR 7x7.
 */
void selectBoard(bool err, int *opsiBoard);

/**
 * Procedure for display information about the games.
 */
void about();

/**
 * Procedure for display players leaderboard.
 */
void scoreMenu();

/**
 * Procedure for start the game.
 */
void playMenu();

/**
 * Procedure for display main menu.
 */
void menu(bool err);

#endif // menu_H
