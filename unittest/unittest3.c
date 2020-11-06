/****************************************
*cs362-assignment3
*Name: Wei Huang
*file:unittest3.c
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

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Ambassador Card----------\n");
  // copy the game state to a test case
  memcpy(&test, &state, sizeof(struct gameState));
  choice1=1
  cardEffect(Ambassador, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);

  newCards=2;
  discarded =2;
  int next =player+1
  printf("hand count (player)= %d, expected = %d\n", test.handCount[player], state.handCount[player] - discarded);
  printf("hand count (nextplayer)= %d, expected = %d\n", test.handCount[next], state.handCount[next] +newCards);
  assert(test.handCount[next] == state.handCount[next] +newCards);
  assert(test.handCount[player] == state.handCount[player] - discarded);




  printf("----------End Testing Ambassador Card----------\n");
}
