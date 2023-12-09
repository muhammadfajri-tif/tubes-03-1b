#if !defined(score_H)
#define score_H
#include <stdio.h>

/**
 * Default file name for storing players scoreboard.
 */
#define DEFAULT_SCOREBOARD_FILE "PlayersScoreboard.dat"

/**
 * Default maximum characters length for username
 */
#define MAX_USERNAME_CHAR 20

/**
 * Record of player data.
 */
typedef struct
{
  /**
   * Username of player with up to max 20 characters.
   */
  char username[MAX_USERNAME_CHAR];

  /**
   * The score obtained when the player wins.
   */
  int score;
} PlayerScore;

/**
 * Open and check file for store scoreboard player. Create file if not exist.
 *
 * @return FILE*
 */
FILE *generateFile(char fileName[], char mode[]);

/**
 * Function to get total players stored in the file.
 *
 * @return int - total player(s).
 */
int getTotalPlayers();

/**
 * Procedure for read score each player.
 */
void readScoreboard(PlayerScore *player);

/**
 * Procedure for update player score to file. If user doesn't exist it will create new record to the file.
 */
void updatePlayerScore(char const *username, int score);

/**
 * Procedure for render player scoreboard in table.
 */
void renderScoreboardTable(PlayerScore *player, int size);

/**
 * Procedure to print sorted scoreboard descending.
 */
void displaySortedScoreboard(PlayerScore player[], int size);

/**
 * Procedure for load all data from file scoreboard.
 *
 * This procedure requires `readScoreboard(PlayerScore *)` and `displaySortedScoreboard(PlayerScore *, int)` to work.
 */
void loadScoreboard();

#endif // score_H