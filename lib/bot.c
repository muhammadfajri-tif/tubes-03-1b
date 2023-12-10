#include <time.h>
#include "bot.h"
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

Move findBestMove(Board **tempBoard, int botDiff)
{
  int bestVal = -1000;
  int maxDepth;
  switch (botDiff)
  {
  case 1:
    maxDepth = 1;
    break;
  case 2:
    maxDepth = 2;
    break;
  case 3:
    maxDepth = 3;
    break;
  default:
    break;
  }
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

void playPvC(Board **board, Board **hintBoard, char *player, int whoseTurn, int botDiff)
{
  int moveCount = 0;
  int row, col;
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
      Move thisMove = findBestMove(tempBoard, botDiff);
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

  if (!gameOver(board) && moveCount == side * side)
  {
    printf("\n\nThe game has ended in a draw\n");
  }
}
