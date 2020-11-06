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

	printf("\n----------Testing Mine Card----------\n");


	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(mine, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);

	if(test.handCount[player]-1 == state.handCount[player])
		printf("Passed hand count is correct\n");
	else
		printf("Failed hand count is not correct\n");


	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where Mine card was added to the players hand\n");
	else
		printf("Failed where Mine card was not added to the players hand\n");


	if(test.playedCardCount == state.playedCardCount)
		printf("Passed where player played Mine card\n");
	else
		printf("Failed where player did not play Mine card\n");


    if(test.coins+3 == state.coins)
  		printf("Passed where player have same coins in Mine card\n");
  	else
  		printf("Failed where player did not have same coins in Mine card\n");

	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed where the Mine was discarded\n");
	else
	{
		printf("Failed where the Mine was not discarded.\n");
	}


	printf("----------End Testing Mine Card----------\n");

}
