/****************************************
*cs362-assignment3
*Name: Wei Huang
*file:unittest5.c
*****************************************/


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
      int coppers[MAX_HAND];
      int silvers[MAX_HAND];
      int golds[MAX_HAND];

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Mine Card----------\n");
  // copy the game state to a test case
  memcpy(&test, &state, sizeof(struct gameState));
  cardEffect(Mine, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);

  int newCards = 0;
  int xtraCoins = 0;
  int discarded = 0;
  int j = state.hand[player][choice1];
  for (i = 0; i < state.handCount[player]; i++)
	{
	  if (state.hand[player][i] == j)
	    {
	      discardcard++;
	      break;
	    }
	}
  printf("hand count = %d, expected = %d\n", test.handCount[player], state.handCount[player] + newCards - discarded);
  printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
  assert(test.handCount[player] == state.handCount[player] + newCards - discarded);
  assert(test.coins == state.coins + xtraCoins);


  printf("----------End Testing Mine Card----------\n");
}
