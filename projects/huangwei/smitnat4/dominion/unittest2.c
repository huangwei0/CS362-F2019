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
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int count1 = 0;
	int count2 = 0;


	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Minion Card----------\n");


	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(minion, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);

	if(test.handCount[player]-1 == state.handCount[player])
		printf("Passed hand count is correct\n");
	else
		printf("Failed hand count is not correct\n");


	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where Minion card was added to the players hand\n");
	else
		printf("Failed where Minion card was not added to the players hand\n");


	if(test.playedCardCount+1 == state.playedCardCount)
		printf("Passed where player played Minion card\n");
	else
		printf("Failed where player did not play Minion card\n");


  printf("-------------------choice 1---------------\n");
  if(test.coins+2 == state.coins)
    printf("Pass where the coins is correct\n");
  else
    printf("Failed wherer the coins is not correct\n");

  printf("------------choice 2-------------\n");
	if(test.discardCount[player]+4 == state.discardCount[player])
		printf("Passed where the Minion was discarded\n");
	else
	{
		printf("Failed where the Minion was not discarded.\n");
	}


  if(test.numActions+1 == state.numActions)
    printf("Passed where two extra action was added\n");
  else
    printf("Failed where two extra action was not added\n");

  printf("----------End Testing Minion Card----------\n");
  }
