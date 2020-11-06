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

	printf("\n----------Testing Ambassador Card----------\n");


	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(ambassador, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);

	if(test.handCount[player]-2 == state.handCount[player])
		printf("Passed hand count is correct\n");
	else
		printf("Failed hand count is not correct\n");


	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where Ambassador card was added to the players hand\n");
	else
		printf("Failed where Ambassador card was not added to the players hand\n");


	if(test.playedCardCount+1 == state.playedCardCount)
		printf("Passed where player played Ambassador card\n");
	else
		printf("Failed where player did not play Ambassador card\n");


	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed where the Ambassador was discarded\n");
	else
	{
		printf("Failed where the Ambassador was not discarded.\n");
	}

	printf("----------End Testing Ambassador Card----------\n");

}
