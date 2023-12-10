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
  else if (*opsiMode == 0)
  {
    playMenu();
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
  printf("2. Medium Computer\n");
  printf("3. Hard Computer\n");
  printf("\n0.Back\n");

  printf("Please choose a number between 1-3: ");
  scanf("%d", &(*opsiBot));

  if (*opsiBot != 1 && *opsiBot != 2 && *opsiBot != 3)
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

  printf("====================================\n");
  printf("|\tTic Tac Toe by BIG R\t   |\n");
  printf("====================================\n");
  printf("     +++++About this Game+++++\n");
  printf("\n\t This Game Made by \n");
  printf("Ahmad Fatan Haidar \t\t231524034\n");
  printf("Muhammad Fajri Ghifari Salman   231524053\n");
  printf("Rio Agasta \t\t\t231524061\n");

  printf("\nPress ENTER to go back ");
  getchar();
  getchar();

  menu(0);
}

/**
 * Procedure for display players leaderboard.
 */
void scoreMenu()
{
  system("cls");

  printf("\n\t\t\033[1;32mPAPAN PERINGKAT\033[1;0m\n");
  loadScoreboard();

  printf("\n\nPress ENTER to go back ");
  getchar();
  getchar();

  menu(0);
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
  char *playername1 = (char *)malloc(25);
  char *playername2 = (char *)malloc(25);
  bool nameErr;

  selectGameMode(0, &mode);
  if (mode == 1)
  {
    selectBot(0, &bot);
  }

  selectBoard(0, &board);
  system("cls");
  printf("Player 1\n");
  inputUsername(playername1);
  if (mode == 2)
  {
    printf("Player 2\n");
    inputUsername(playername2);
  }
  else
  {
    playername2 = "";
  }
  tictactoe(mode, bot, board, playername1, playername2);
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
