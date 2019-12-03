#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int count1 = 0;
	int count2 = 0;


	initializeGame(numPlayers, k, seed, &state);
  printf("\n----------Testing bonus----------\n");
	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(feast, choice1, choice2, choice3, &state, handpos, &bonus);
	player = whoseTurn(&test);
  if(test.coins+5 == state.coins)
    printf("Passed where the feast was add coins.\n");
  else
  {
    printf("Failed where the feast was not add coins.\n");
  }

  memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);
	player = whoseTurn(&test);
  if(test.coins+4 == state.coins)
    printf("Passed where the baron was add coins.\n");
  else
  {
    printf("Failed where the baron was not add coins.\n");
  }

  memcpy(&test, &state, sizeof(struct gameState));
  cardEffect(minion, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);
  if(test.coins+2 == state.coins)
    printf("Passed where the minion was add coins.\n");
  else
  {
    printf("Failed where the minion was not add coins.\n");
  }

  memcpy(&test, &state, sizeof(struct gameState));
  cardEffect(steward, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);
  if(test.coins+2 == state.coins)
    printf("Passed where the minion was add coins.\n");
  else
  {
    printf("Failed where the minion was not add coins.\n");
  }

  memcpy(&test, &state, sizeof(struct gameState));
  cardEffect(tribute, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);
  if(test.coins+2 == state.coins)
    printf("Passed where the tribute was add coins.\n");
  else
  {
    printf("Failed where the tribute was not add coins.\n");
  }


  printf("\n----------Testing bonus end----------\n");
}
