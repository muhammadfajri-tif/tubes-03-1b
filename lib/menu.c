#include "menu.h"
#include "game.c"

/**
 * Procedure for setting game mode whether it's player vs player OR player vs computer.
 */
void selectGameMode(bool err, int *opsiMode)
{
  system("cls");

  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("   +++++Choose Game Mode+++++\n\n");
  if (err)
  {
    printf("ERROR: Please choose a number between 1-2!\n\n");
  }
  printf("1. Player vs Computer\n");
  printf("2. Player vs Player\n");
  printf("\n0.Back\n\n");

  printf("Please choose a number between 1-2: ");
  scanf("%d", &(*opsiMode));

  if (*opsiMode != 1 && *opsiMode != 2)
  {
    selectGameMode(1, opsiMode);
  }
}

/**
 * Procedure for setting computer/bot difficulty.
 */
void selectBot(bool err, int *opsiBot)
{
  system("cls");

  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("     +++++Choose Difficulty+++++\n\n");
  if (err)
  {
    printf("ERROR: Please choose a number between 1-2!\n\n");
  }
  printf("1. Easy Computer\n");
  printf("2. Hard Computer\n");
  printf("\n0.Back\n");

  printf("Please choose a number between 1-2: ");
  scanf("%d", &(*opsiBot));

  if (*opsiBot != 1 && *opsiBot != 2)
  {
    selectBot(1, opsiBot);
  }
}

/**
 * Procedure for setting board size whether it's 3x3, 5x5, OR 7x7.
 */
void selectBoard(bool err, int *opsiBoard)
{
  system("cls");

  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("    +++++Choose Board Size+++++\n\n");
  if (err)
  {
    printf("ERROR: Please choose a number between 1-3!\n\n");
  }
  printf("1. 3x3 Board\n");
  printf("2. 5x5 Board\n");
  printf("3. 7x7 Board\n");

  printf("\nPlease choose a number between 1-3: ");
  scanf("%d", &(*opsiBoard));

  if (*opsiBoard != 1 && *opsiBoard != 2 && *opsiBoard != 3)
  {
    selectBoard(1, opsiBoard);
  }
}

/**
 * Procedure for display information about the games.
 */
void about()
{
  system("cls");

  int opsi;

  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("     +++++About this Game+++++\n");
  printf("\n\t This Game Made by \n");
  printf("Ahmad Fatan Haidar \t\t231524034\n");
  printf("Muhammad Fajri Ghifari Salman   231524053\n");
  printf("Rio Agasta \t\t\t231524061");
  printf("\n\n0.Back\n\n");

  printf("Please insert a number: ");
  scanf("%d", &opsi);

  menu(0);
}

/**
 * Procedure for display players leaderboard.
 */
void scoreMenu()
{
  // TODO: implementasi file manipulation
  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("     +++++High Score List+++++\n\n");
  printf("1. (Player 1) (Score)\n");
  printf("2. (Player 2) (Score)\n");
  printf("3. (Player 3) (Score)\n");
  printf("\n\n0.Back\n");
}

/**
 * Procedure for start the game.
 */
void playMenu()
{
  system("cls");

  int mode;
  int bot = 0;
  int board;
  char *namaplayer1 = (char *)malloc(25);
  char *namaplayer2 = (char *)malloc(25);
  bool nameErr;

  selectGameMode(0, &mode);
  if (mode == 1)
  {
    selectBot(0, &bot);
  }

  selectBoard(0, &board);
  system("cls");
  printf("Player 1\n");
  inputUsername(namaplayer1);
  if (mode == 2)
  {
    printf("Player 2\n");
    inputUsername(namaplayer2);
  }
  else
  {
    namaplayer2 = "";
  }
  tictactoe(mode, bot, board, namaplayer1, namaplayer2);
}

/**
 * Procedure for display main menu.
 */
void menu(bool err)
{
  system("cls");

  int opsiMenu;

  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("\t+++++Main Menu+++++\n\n");
  if (err)
  {
    printf("ERROR: Please choose a number between 1-4!\n\n");
  }
  printf("1. Play\n");
  printf("2. High Score\n");
  printf("3. About\n");
  printf("4. Quit\n");

  printf("\nPlease choose a number between 1-4: ");
  scanf("%d", &opsiMenu);

  switch (opsiMenu)
  {
  case 1:
    playMenu();
    break;
  case 2:
    scoreMenu();
    break;
  case 3:
    about();
    break;
  case 4:
    exit(0);
    break;
  default:
    menu(1);
    break;
  }
}