/****************************************
*cs362-assignment3
*Name: Wei Huang
*file:unittest4.c
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
   int shuffledCards = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Tribute Card----------\n");
  // copy the game state to a test case
  memcpy(&test, &state, sizeof(struct gameState));
  cardEffect(Tribute, choice1, choice2, choice3, &state, handpos, &bonus);
  player = whoseTurn(&test);
  int next =player+1;
printf("\n----------Test1: state.discardCount[next] + state.deckCount[next]) <= 1----------\n");
  if ((state.discardCount[next] + state.deckCount[next]) <= 1){
if (state.deckCount[next] > 0||state->discardCount[nextPlayer] > 0){
  discarded=state.discardCount[next]--;
  printf("deck count = %d, expected = %d\n", test.deckCount[next], state.deckCount[next] - newCards + shuffledCards);
  assert(test.deckCount[player] == state.deckCount[player] - newCards + shuffledCards);
}
printf("\n----------Test2: else----------\n");
else{
  if (state.deckCount[next] == 0){
    for (i = 0; i < state.discardCount[next]; i++){
     state.deck[next][i] = state.discard[next][i];//Move to deck
     state.deckCount[next]++;
     state.discard[next][i] = -1;
     discraeded=state.discardCount[next]--;
     printf("deck count = %d, expected = %d\n", test.deckCount[next], state.deckCount[next] - newCards + shuffledCards);
     assert(test.deckCount[player] == state.deckCount[player] - newCards + shuffledCards);
    }
  }
  tributeRevealedCards[0] = state.deck[next][state.deckCount[next]-1];
  state.deck[next][state.deckCount[next]--] = -1;
  state.deckCount[next]--;
  tributeRevealedCards[1] = state.deck[next][state.deckCount[next]-1];
  state.deck[next][state.deckCount[next]--] = -1;
  state.deckCount[next]--;
   }
printf("\n----------Test3: tributeRevealedCards[0] == tributeRevealedCards[1]----------\n");
 if (tributeRevealedCards[0] == tributeRevealedCards[1]){//If we have a duplicate card, just drop one
state.playedCards[state.playedCardCount] = tributeRevealedCards[1];
state.playedCardCount++;
tributeRevealedCards[1] = -1;
 }

 for (i = 0; i <= 2; i ++){
if (tributeRevealedCards[i] == copper || tributeRevealedCards[i] == silver || tributeRevealedCards[i] == gold){//Treasure cards
  xtraCoins = 2;
  printf("coins = %d, expected = %d\n", test.coins, state.coins + xtraCoins);
  ssert(test.coins == state.coins + xtraCoins);
}
else{//Action Card
int num =2
printf("num Actions = %d, expected = %d\n", test.numberActions, state.numberActions+number);
assert(test.numberActions == state.numberActions+number);
}
 }

  printf("----------End Testing Tribute Card----------\n");
}
