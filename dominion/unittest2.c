/****************************************
*cs362-assignment3
*Name: Wei Huang
*file:unittest2.c
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

	printf("\n----------Testing Minion Card----------\n");
  printf("\n----------Test1: choice1 = 1 = +2 coins----------\n");
  // copy the game state to a test case
  memcpy(&test, &state, sizeof(struct gameState));
  choice1=1
  cardEffect(MInion, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);

  newCards = 0;
  xtraCoins = 2;
  discarded = 1;
  printf("hand count = %d, expected = %d\n", test.handCount[player], state.handCount[player] + newCards - discarded);
  printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
  assert(test.handCount[player] == state.handCount[player] + newCards - discarded);
  assert(test.coins == state.coins + xtraCoins);

  printf("\n----------Test2: choice1 = 2 = discard hand, redraw 4, other players with 5+ cards discard hand and draw 4----------\n");
  // copy the game state to a test case
  memcpy(&test, &state, sizeof(struct gameState));
  choice1=2
  cardEffect(MInion, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);
  int next= player+1;
  newCards = 4;
  xtraCoins = 0;
  discarded = state.handCount[player];
  printf("hand count = %d, expected = %d\n", test.handCount[player], state.handCount[player] + newCards - discarded);
  printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
  assert(test.handCount[player] == state.handCount[player] + newCards - discarded);
  assert(test.coins == state.coins + xtraCoins);

  discar = state.handCount[next];
  for (i = 0; i < state->numPlayers; i++){
    if(i!=player){
      if(state.handCount[i]>0){
        printf("hand count = %d, expected = %d\n", test.handCount[next], state.handCount[next] + newCards - discarded);
        printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
        assert(test.handCount[next] == state.handCount[next] + newCards - discar);
        assert(test.coins == state.coins + xtraCoins);
      }
    }
  }


  printf("----------End Testing Minion Card----------\n");
}
