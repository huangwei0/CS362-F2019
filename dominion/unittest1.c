/****************************************
*cs362-assignment3
*Name: Wei Huang
*file:unittest1.c
*****************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void main()
{
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
      int newCards, xtraCoins, discarded;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Baron Card----------\n");
	printf("\n----------Test1: Found an estate card = +4 coins ----------\n");
  // copy the game state to a test case
  memcpy(&test, &state, sizeof(struct gameState));
  choice1 > 0;
  cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);


  newCards = 0;
  xtraCoins = 4;
  discarded = 1;
  int p=0;
  if(state.hand[player][p]==estate){
    printf("hand count = %d, expected = %d\n", test.handCount[player], state.handCount[player] + newCards - discarded);
    printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
    assert(test.handCount[player] == state.handCount[player] + newCards - discarded);
    assert(test.coins == state.coins + xtraCoins);
  }

  printf("\n----------Test2: gain estate ----------\n");
  memcpy(&test, &state, sizeof(struct gameState));
  choice1 <= 0;
  cardEffect(baron, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);


   newCards = 1;
   xtraCoins = 0;
   discarded = 0;

  printf("hand count = %d, expected = %d\n", test.handCount[player], state.handCount[player] + newCards - discarded);
  printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
  assert(test.handCount[player] == state.handCount[player] + newCards - discarded);
  assert(test.coins == state.coins + xtraCoins);


	printf("----------End Testing Baron Card----------\n");
}
