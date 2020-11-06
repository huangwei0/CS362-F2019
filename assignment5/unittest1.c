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

	printf("\n----------Testing Baron Card----------\n");


	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);

	if(test.handCount[player]-1 == state.handCount[player])
		printf("Passed hand count is correct\n");
	else
		printf("Failed hand count is not correct\n");


	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where Baron card was added to the players hand\n");
	else
		printf("Failed where Baron card was not added to the players hand\n");


	if(test.playedCardCount+1 == state.playedCardCount)
		printf("Passed where player played Baron card\n");
	else
		printf("Failed where player did not play Baron card\n");



	for (i = 0; i < state.handCount[0]; i++)
    {
        if(state.hand[0][i] = estate);
			count1++;
    }

	for (i = 0; i < test.handCount[0]; i++)
    {
        if(test.hand[0][i] = estate);
			count2++;
    }

	if(count1 == count2-1)
    if(test.coins +4 ==state.coins){
		    printf("Passed where there is no variance in estate cards\n");
        printf("Passed where the coins is alrady add\n");
    }
    else{
      printf("Failed where the coins is not add\n");
    }
  else
		printf("Failed where there is a variance in estate cards\n");


	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed where the Baron was discarded\n");
	else
	{
		printf("Failed where the Baron was not discarded.\n");
	}


	printf("----------End Testing Baron Card----------\n");

}
