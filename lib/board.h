#if !defined(board_H)
#define board_H

/**
 * Data type for game board.
 */
typedef struct
{
  char *str;
} Board;

/**
 * Function for create game board based on it's size.
 *
 * @return Board
 */
Board **createBoard(int side);

/**
 * Procedure for render placeholder game board.
 */
void boardTemplate(Board **board, int row);

/**
 * Procedure for render filled game board.
 */
void showBoard(Board **board, Board **hintBoard);

/**
 * Procedure for clear the board.
 */
void emptyBoard(Board **board);

#endif // board_H
