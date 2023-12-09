#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

/**
 * Declare variable global for board's size.
 */
int side;

/**
 * Function for create game board based on it's size.
 *
 * @return Board
 */
Board **createBoard(int side)
{
  // alocate memory based on side for 2D array
  Board **board = (Board **)malloc(side * sizeof(Board *));

  for (int i = 0; i < side; i++)
  {
    // Allocate memory for each row (array of Board)
    board[i] = (Board *)malloc(side * sizeof(Board));
  }

  return board;
}

/**
 * Procedure for render placeholder game board.
 */
void boardTemplate(Board **board, int row)
{
  // Hint Board
  switch (side)
  {
  case 3: // board 3x3
    printf("\t\t\t %s | %s | %s \n", board[row][0].str, board[row][1].str, board[row][2].str);
    if (row < side - 1)
      printf("\t\t\t------------\n");
    break;
  case 5: // board 5x5
    if ((row == 0 || row == 1) && (strcmp(board[0][0].str, "1") == 0))
    {
      printf("\t\t\t  %s |  %s |  %s |  %s | %s \n",
             board[row][0].str, board[row][1].str, board[row][2].str, board[row][3].str, board[row][4].str);
    }
    else
    {
      printf("\t\t\t %s | %s | %s | %s | %s \n",
             board[row][0].str, board[row][1].str, board[row][2].str, board[row][3].str, board[row][4].str);
    }

    if (row < side - 1)
    {
      if (strcmp(board[0][0].str, "1") == 0)
      {
        printf("\t\t\t-------------------------\n");
      }
      else
      {
        printf("\t\t\t--------------------\n");
      }
    }
    break;
  case 7: // board 7x7
    if ((row == 0) && (strcmp(board[0][0].str, "1") == 0))
    {
      printf("\t\t\t  %s |  %s |  %s |  %s |  %s |  %s | %s \n",
             board[row][0].str, board[row][1].str, board[row][2].str, board[row][3].str, board[row][4].str, board[row][5].str, board[row][6].str);
    }
    else if ((row == 1) && (strcmp(board[0][0].str, "1") == 0))
    {
      printf("\t\t\t  %s |  %s | %s | %s | %s | %s | %s \n",
             board[row][0].str, board[row][1].str, board[row][2].str, board[row][3].str, board[row][4].str, board[row][5].str, board[row][6].str);
    }
    else
    {
      printf("\t\t\t %s | %s | %s | %s | %s | %s | %s \n",
             board[row][0].str, board[row][1].str, board[row][2].str, board[row][3].str, board[row][4].str, board[row][5].str, board[row][6].str);
    }

    if (row < side - 1)
    {
      if (strcmp(board[0][0].str, "1") == 0)
      {
        printf("\t\t\t-----------------------------------\n");
      }
      else
      {
        printf("\t\t\t---------------------------\n");
      }
    }
    break;
  default:
    break;
  }
}

/**
 * Procedure for render filled game board.
 */
void showBoard(Board **board, Board **hintBoard)
{
  int placeHolder = 1;
  for (int i = 0; i < side; i++)
  {
    for (int j = 0; j < side; j++)
    {
      hintBoard[i][j].str = (char *)malloc(3);
      sprintf(hintBoard[i][j].str, "%d", placeHolder);
      placeHolder++;
    }
  }
  printf("\n\n");
  // Print board untuk hint
  for (int i = 0; i < side; i++)
  {
    boardTemplate(hintBoard, i);
  }
  printf("\n\n\n");
  // Print board untuk permainan
  for (int i = 0; i < side; i++)
  {
    boardTemplate(board, i);
  }
}

/**
 * Procedure for clear the board.
 */
void emptyBoard(Board **board)
{
  for (int i = 0; i < side; i++)
  {
    for (int j = 0; j < side; j++)
    {
      board[i][j].str = " ";
    }
  }
}

int foo;