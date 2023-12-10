#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/boolean.h"
#include "score.h"

/**
 * Open and check file. Create file if not exist.
 *
 * @return FILE*
 */
FILE *generateFile(char fileName[], char mode[])
{
  FILE *file = fopen(fileName, mode);
  int stillError = 0;

  if (file == NULL)
  {
    printf("\033[1;33m[WARN]\t\033[1;0mFile for storing players' score not found!\n");
    printf("\033[1;34m[INFO]\t\033[1;0mCreating leaderboard file.\n");
    file = fopen(DEFAULT_SCOREBOARD_FILE, "wb");

    if (file == NULL)
      stillError = 1;

    if (!stillError)
      printf("\033[1;34m[INFO]\t\033[1;0mSuccessfully created leaderboard file.\n");
  }

  if (stillError)
  {
    printf("\033[1;31m[ERR]\t\033[1;0mFailed to create leaderboard file. Please check your storage/file's permission.\n");
    exit(1);
  }
  return file;
}

/**
 * Function to get total players stored in the file.
 *
 * @return int - total player(s).
 */
int getTotalPlayers()
{
  FILE *scoreboardFile = generateFile(DEFAULT_SCOREBOARD_FILE, "rb");

  int listLength = 0; // dynamic memory allocation for score board array
  int curLine;

  while ((curLine = fgetc(scoreboardFile)) != EOF)
  {
    if (curLine == '\n')
      listLength++;
  }
  fclose(scoreboardFile);
  return listLength;
}

/**
 * Procedure for read score each player.
 */
void readScoreboard(PlayerScore *player)
{
  FILE *scoreboardFile = generateFile(DEFAULT_SCOREBOARD_FILE, "rb");
  int i = 0;

  // Get data from file line by line and store it to player array until EOF
  while (fscanf(scoreboardFile, "%[^,],%d\n", (player + i)->username, &(player + i)->score) != EOF)
  {
    i++;
  }
}

/**
 * Procedure for update player score to file. If user doesn't exist it will create new record to the file.
 */
void updatePlayerScore(char const *username, int score)
{
  FILE *scoreboardFile;
  bool found = false;
  int i = 0;

  // load players
  int length = getTotalPlayers();
  PlayerScore *players = malloc(sizeof(PlayerScore) * length);
  readScoreboard(players);

  // find username
  while (i < length && !found)
  {
    // if found increment current score with the new score
    if (strcmp((players + i)->username, username) == 0)
    {
      (players + i)->score += score;
      found = true;
      printf("\nplayer: %s", (players + i)->username);
      printf("\nscore: %d", (players + i)->score);
    }
    i++;
  }

  // if username not found, add user as a new record
  if (!found)
  {
    scoreboardFile = generateFile(DEFAULT_SCOREBOARD_FILE, "ab");
    fprintf(scoreboardFile, "%s,%d\n", username, score);
    fclose(scoreboardFile);
  }
  else // if username found, update the record
  {
    scoreboardFile = generateFile(DEFAULT_SCOREBOARD_FILE, "wb");
    for (int i = 0; i < length; i++)
    {
      fprintf(scoreboardFile, "%s,%d\n", (players + i)->username, (players + i)->score);
    }
    fclose(scoreboardFile);
  }
}

/**
 * Procedure for render player scoreboard in table.
 */
void renderScoreboardTable(PlayerScore *player, int size)
{
  if (size != 0)
  {
    printf("\n+-------+---------------------------+-------+\n");
    printf("| Rank  | Username                  | Score |\n");
    printf("+-------+---------------------------+-------+\n");
    for (int i = 0; i < size; i++)
    {
      printf("| %d\t| %-25s | %3d   |\n", i + 1, (player + i)->username, (player + i)->score);
    }
    printf("+-------+---------------------------+-------+\n");
  }
  else
  {
    printf("\n+-----------------------------------------------+\n");
    printf("|\t\tNo Data Available\t\t|\n");
    printf("+-----------------------------------------------+\n");
  }
}

/**
 * Procedure to print sorted scoreboard descending.
 */
void displaySortedScoreboard(PlayerScore player[], int size)
{
  int i, j;
  PlayerScore key, playerTemp;

  // sorting desc
  for (i = 1; i < size; i++)
  {
    key = player[i];
    playerTemp = player[i];
    j = i - 1;

    while (j >= 0 && player[j].score < key.score)
    {
      player[j + 1] = player[j];
      j--;
    }

    player[j + 1] = playerTemp;
  }
  // output the sorted score board
  renderScoreboardTable(player, size);
}

/**
 * Procedure for load all data from file.
 *
 * Note: This procedure requires `readScoreboard(PlayerScore *)` and `renderScoreboardTable(PlayerScore *, int)` to work.
 */
void loadScoreboard()
{
  int length = getTotalPlayers();

  PlayerScore *scoreboardPlayers = malloc(sizeof(PlayerScore) * length);
  readScoreboard(scoreboardPlayers);

  // sort score, then display it
  displaySortedScoreboard(scoreboardPlayers, length);

  free(scoreboardPlayers);
}