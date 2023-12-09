#include <time.h>
#include "game.h"
#include "board.c"

/**
 * Declare global variable for set winner condition.
 */
int winCondition;

/**
 * Declare global variable for each player symbol. Used for bot.
 */
char *player = "x", *opponent = "o";

bool isMovesLeft(Board **tempBoard)
{
  for (int i = 0; i < side; i++)
  {
    for (int j = 0; j < side; j++)
    {
      if (tempBoard[i][j].str == "_")
      {
        return true;
      }
    }
  }

  return false;
}

int evaluate(Board **tempBoard)
{
  // Evaluate Row
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side - 1; j++)
    {
      if (tempBoard[i][j].str == tempBoard[i][j + 1].str && tempBoard[i][j].str != "_")
      {
        count++;
        if (count == winCondition - 1)
        {
          if (tempBoard[i][j].str == player)
          {
            return +10;
          }
          else if (tempBoard[i][j].str == opponent)
          {
            return -10;
          }
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Evaluate Column
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side - 1; j++)
    {
      if (tempBoard[j][i].str == tempBoard[j + 1][i].str && tempBoard[j][i].str != "_")
      {
        count++;
        if (count == winCondition - 1)
        {
          if (tempBoard[j][i].str == player)
          {
            return +10;
          }
          else if (tempBoard[j][i].str == opponent)
          {
            return -10;
          }
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Evaluate Diagonal
  // Main diagonal geser ke bawah
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (tempBoard[i + j][j].str == tempBoard[i + j + 1][j + 1].str && tempBoard[i + j][j].str != "_")
      {
        count++;
        if (count == winCondition - 1)
        {
          if (tempBoard[i + j][j].str == player)
          {
            return +10;
          }
          else if (tempBoard[i + j][j].str == opponent)
          {
            return -10;
          }
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Main diagonal geser ke kanan
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (tempBoard[j][i + j].str == tempBoard[j + 1][i + j + 1].str && tempBoard[i][i + j].str != "_")
      {
        count++;
        if (count == winCondition - 1)
        {
          if (tempBoard[j][i + j].str == player)
          {
            return +10;
          }
          else if (tempBoard[j][i + j].str == opponent)
          {
            return -10;
          }
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Anti diagonal geser ke bawah
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (tempBoard[i + j][side - 1 - j].str == tempBoard[i + j + 1][side - 1 - j - 1].str && tempBoard[i + j][side - 1 - j].str != "_")
      {
        count++;
        if (count == winCondition - 1)
        {
          if (tempBoard[i + j][side - 1 - j].str == player)
          {
            return +10;
          }
          else if (tempBoard[i + j][side - 1 - j].str == opponent)
          {
            return -10;
          }
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  // Anti diagonal geser ke kiri
  for (int i = 0; i < side; i++)
  {
    int count = 0;
    for (int j = 0; j < side; j++)
    {
      if (i + j + 1 > side - 1)
      {
        break;
      }

      if (tempBoard[j][side - 1 - j - i].str == tempBoard[j + 1][side - 1 - j - i - 1].str && tempBoard[j][side - 1 - j - i].str != "_")
      {
        count++;
        if (count == winCondition - 1)
        {
          if (tempBoard[j][side - 1 - j - i].str == player)
          {
            return +10;
          }
          else if (tempBoard[j][side - 1 - j - i].str == opponent)
          {
            return -10;
          }
        }
      }
      else
      {
        count = 0;
      }
    }
  }

  return 0;
}

int minimax(Board **tempBoard, int depth, int maxDepth, bool isMax)
{
  int score = evaluate(tempBoard);

  if (score == 10 || score == -10 || depth == maxDepth)
  {
    return score;
  }

  // if (score == -10)
  // {
  //     return score;
  // }

  if (isMovesLeft(tempBoard) == false)
  {
    return 0;
  }

  if (isMax)
  {
    int best = -1000;

    for (int i = 0; i < side; i++)
    {
      for (int j = 0; j < side; j++)
      {
        if (tempBoard[i][j].str == "_")
        {
          tempBoard[i][j].str = player;
          int val = minimax(tempBoard, depth + 1, maxDepth, !isMax);
          if (val > best)
          {
            best = val;
          }
          tempBoard[i][j].str = "_";
        }
      }
    }

    return best;
  }
  else
  {
    int best = 1000;

    for (int i = 0; i < side; i++)
    {
      for (int j = 0; j < side; j++)
      {
        if (tempBoard[i][j].str == "_")
        {
          tempBoard[i][j].str = opponent;
          int val = minimax(tempBoard, depth + 1, maxDepth, !isMax);
          if (val < best)
          {
            best = val;
          }
          tempBoard[i][j].str = "_";
        }
      }
    }

    return best;
  }
}

Move findBestMove(Board **tempBoard)
{
  int bestVal = -1000;
  int maxDepth = 3;
  Move bestMove;
  bestMove.row = -1;
  bestMove.col = -1;

  for (int i = 0; i < side; i++)
  {
    for (int j = 0; j < side; j++)
    {
      if (tempBoard[i][j].str == "_")
      {
        tempBoard[i][j].str = player;
        int moveVal = minimax(tempBoard, 0, maxDepth, false);
        tempBoard[i][j].str = "_";

        if (moveVal > bestVal)
        {
          bestMove.row = i;
          bestMove.col = j;
          bestVal = moveVal;
        }
      }
    }
  }

  return bestMove;
}

bool rowCrossed(Board **board)
{
  int count = 0;
  for (int i = 0; i < side; i++)
  {
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
  int count = 0;
  for (int i = 0; i < side; i++)
  {
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

      if (board[j][i + j].str == board[j + 1][i + j + 1].str && board[i][i + j].str != " ")
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
void declareWinner(int whoseTurn, char *namaplayer)
{
  if (whoseTurn == COMPUTER)
  {
    printf("Computer has won the game\n");
  }
  else
  {
    printf("%s has won the game\n", namaplayer);
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
      printf("Error! Username is not valid, Please dont use Comma (,) or Spaces in your username.\n");
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

/**
 * Procedure for randomize bot's movement.
 */
void randomizeMove(int moves[])
{
  srand(time(NULL));

  for (int i = 0; i < side * side; i++)
  {
    moves[i] = i;
  }

  for (int i = 0; i < side * side; i++)
  {
    int randomIdx = rand() % (side * side);
    int temp = moves[i];
    moves[i] = moves[randomIdx];
    moves[randomIdx] = temp;
  }
}

void playPvC(Board **board, Board **hintBoard, char *player, int whoseTurn, int botDiff)
{
  int moveCount = 0;
  int row, col;
  if (botDiff == 1)
  {
    /* code */
  }
  else if (botDiff == 2)
  {
    while (!gameOver(board) && moveCount != side * side)
    {
      if (whoseTurn == PLAYER1)
      {
        int move;
        inputMove(&move, player);
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
            declareWinner(PLAYER1, player);
            return;
          }
          whoseTurn = COMPUTER;
        }
        else
        {
          printf("Cell %d is already occupied. Try again.\n", move);
        }
      }
      else if (whoseTurn == COMPUTER)
      {
        Board **tempBoard = createBoard(side);
        for (int i = 0; i < side; i++)
        {
          for (int j = 0; j < side; j++)
          {
            if (board[i][j].str == "X")
            {
              tempBoard[i][j].str = "x";
            }
            else if (board[i][j].str == "O")
            {
              tempBoard[i][j].str = "o";
            }
            else if (board[i][j].str == " ")
            {
              tempBoard[i][j].str = "_";
            }
          }
        }
        Move thisMove = findBestMove(tempBoard);
        row = thisMove.row;
        col = thisMove.col;

        board[row][col].str = PLAYER2SYMBOL;
        system("cls");
        showBoard(board, hintBoard);
        moveCount++;
        if (gameOver(board))
        {
          declareWinner(COMPUTER, "");
        }
        whoseTurn = PLAYER1;
      }
    }
  }

  if (!gameOver(board) && moveCount == side * side)
  {
    printf("The game has ended in a draw\n");
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

  int moves[side * side];
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
}