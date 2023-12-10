#include "game.h"
#include "bot.c"

bool rowCrossed(Board **board)
{
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side - 1; j++)
    {
      if (board[i][j].str == board[i][j + 1].str && board[i][j].str != " ")
      {
        count++;
        if (count == winCondition - 1)
        {
          return true;
        }
      }
      else
      {
        count = 0;
      }
    }
  }
  return false;
}

bool colCrossed(Board **board)
{
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side - 1; j++)
    {
      if (board[j][i].str == board[j + 1][i].str && board[j][i].str != " ")
      {
        count++;
        if (count == winCondition - 1)
        {
          return true;
        }
      }
      else
      {
        count = 0;
      }
    }
  }
  return false;
}

bool diagCrossed(Board **board)
{
  // Check main diagonal geser ke bawah
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (board[i + j][j].str == board[i + j + 1][j + 1].str && board[i + j][j].str != " ")
      {
        count++;
        if (count == winCondition - 1)
        {
          return true;
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Check main diagonal geser ke kanan
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (board[j][i + j].str == board[j + 1][i + j + 1].str && board[j][i + j].str != " ")
      {
        count++;
        if (count == winCondition - 1)
        {
          return true;
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Check anti-diagonal geser ke bawah
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (board[i + j][side - 1 - j].str == board[i + j + 1][side - 1 - j - 1].str && board[i + j][side - 1 - j].str != " ")
      {
        count++;
        if (count == winCondition - 1)
        {
          return true;
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Check anti-diagonal geser ke kiri
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (board[j][side - 1 - j - i].str == board[j + 1][side - 1 - j - i - 1].str && board[j][side - 1 - j - i].str != " ")
      {
        count++;
        if (count == winCondition - 1)
        {
          return true;
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  return false;
}

bool gameOver(Board **board)
{
  return (rowCrossed(board) || colCrossed(board) || diagCrossed(board));
}

/**
 * Procedure for determine which player wins the game.
 */
void declareWinner(int whoseTurn, char *playername)
{
  if (whoseTurn == COMPUTER)
  {
    printf("Computer has won the game\n");
  }
  else
  {
    printf("%s has won the game\n", playername);
  }
}

/**
 * Procedure for input and validate player's username.
 */
void inputUsername(char *username)
{
  bool err;
  do
  {
    printf("Please enter your name: ");
    getchar();
    scanf("%24[^\n]s", username);

    err = false;
    for (int i = 0; i < strlen(username); i++)
    {
      if (username[i] == ',' || username[i] == ' ')
      {
        err = true;
        break;
      }
    }
    // jika ada comma pada username
    if (err)
    {
      printf("\033[1;31m[ERR]\t\033[1;0mUsername is not valid, Please dont use Comma (,) or Spaces in your username.\n");
    }
  } while (err);
}

/**
 * Procedure for input/fill the game board.
 */
void inputMove(int *move, char *playername)
{
  int val;
  int maxNumber = side * side;
  printf("(%s) Enter your move: ", playername);
  val = scanf("%d", move);
  if (val == 0)
  {
    printf("Please enter a number!\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    inputMove(move, playername);
  }
  else
  {
    if (*move < 1 || *move > maxNumber)
    {
      printf("Please enter a number between 1-%d!\n", maxNumber);
      inputMove(move, playername);
    }
  }
}

void playPvP(Board **board, Board **hintBoard, char *player1, char *player2, int whoseTurn)
{
  int moveCount = 0;
  int row, col;
  while (!gameOver(board) && moveCount != side * side)
  {
    if (whoseTurn == PLAYER1)
    {
      int move;
      inputMove(&move, player1);
      row = (move - 1) / side;
      col = (move - 1) % side;
      if (board[row][col].str == " ")
      {
        board[row][col].str = PLAYER1SYMBOL;
        system("cls");
        showBoard(board, hintBoard);
        moveCount++;
        if (gameOver(board))
        {
          declareWinner(PLAYER1, player1);
          return;
        }
        whoseTurn = PLAYER2;
      }
      else
      {
        printf("Cell %d is already occupied. Try again.\n", move);
      }
    }
    else if (whoseTurn == PLAYER2)
    {
      int move;
      inputMove(&move, player2);
      row = (move - 1) / side;
      col = (move - 1) % side;
      if (board[row][col].str == " ")
      {
        board[row][col].str = PLAYER2SYMBOL;
        system("cls");
        showBoard(board, hintBoard);
        moveCount++;
        if (gameOver(board))
        {
          declareWinner(PLAYER2, player2);
          return;
        }
        whoseTurn = PLAYER1;
      }
      else
      {
        printf("Cell %d is already occupied. Try again.\n", move);
      }
    }
  }

  if (!gameOver(board) && moveCount == side * side)
  {
    printf("\n\nThe game has ended in a draw\n");
  }
}

void rematch(bool err, int mode, int bot, int board, char *player1, char *player2)
{

  int input;

  // Out the error msg
  if (err)
  {
    printf("\033[1;31m[ERR]\t\033[1;0mInvalid input. Try again.");
  }

  printf("\n\n1. Rematch");
  printf("\n2. Go back to main menu");
  printf("\n3. Exit game");
  printf("\n\nPlease enter a number between 1-3: ");
  scanf("%d", &input);
  getchar(); // clear input; resolve the infinity loop

  // conditional for user input
  switch (input)
  {
  case 1:
    tictactoe(mode, bot, board, player1, player2);
    break;
  case 2:
    menu(0);
    break;
  case 3:
    exit(0);
    break;
  default:
    // if user not type 1 OR 2 OR 3; then repreat this procedure with error msg
    rematch(1, mode, bot, board, player1, player2);
    break;
  }
}

void tictactoe(int gameMode, int botDiff, int boardSize, char *player1, char *player2)
{
  switch (boardSize)
  {
  case 1:
    side = 3;
    winCondition = 3;
    break;
  case 2:
    side = 5;
    winCondition = 4;
    break;
  case 3:
    side = 7;
    winCondition = 5;
    break;
  default:
    break;
  }

  Board **board = createBoard(side);
  emptyBoard(board);
  Board **hintBoard = createBoard(side);
  showBoard(board, hintBoard);

  if (gameMode == 1)
  {
    // Mulai permainan player vs komputer dengan giliran pertama PLAYER1
    playPvC(board, hintBoard, player1, PLAYER1, botDiff);
  }
  else if (gameMode == 2)
  {
    // Mulai permainan player vs player dengan giliran pertama PLAYER1
    playPvP(board, hintBoard, player1, player2, PLAYER1);
  }

  rematch(0, gameMode, botDiff, boardSize, player1, player2);
}
