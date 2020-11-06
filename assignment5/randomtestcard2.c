#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include<time.h>

int main(){
  int i, n, r, p, handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron,great_hall};

  struct gameState G, test;
  printf("Testing  minion\n");
  printf("RANDOM TESTS\n");
  for(n=0; n<50; n++){
     int players = (rand() % 50);
     int seed =(rand() % 5000);

     initializeGame(players, k, seed, &G);
     printf("\n--------Running round %d/50--------\n", n+1);
     memcpy(&test, &G, sizeof(struct gameState));
     cardEffect( minion, choice1, choice2, choice3, &G, handpos, &bonus);

     p = whoseTurn(&test);

     if(G.hand[p][test.handCount[p]-1] != -1)
       printf("Passed where  minion card was added to the players hand\n");
     else
       printf("Failed where  minion card was not added to the players hand\n");


     if(test.playedCardCount+1 == G.playedCardCount)
       printf("Passed where player played  minion card\n");
     else
       printf("Failed where player did not play  minion card\n");

      if(test.coins +2 == G.coins)
        printf("Passed where coins corect in minion card\n");
      else
        printf("Failed where player did not counct correct coins in minion card\n");

     if(test.discardCount[p] == G.discardCount[p])
       printf("Passed where the  minion was discarded\n");
     else
     {
       printf("Failed where the  minion was not discarded.\n");
     }


     if(test.numActions+1 == G.numActions)
       printf("Passed where an extra action was added\n");
     else
       printf("Failed where an extra action was not added\n");

    }
    printf("\nTEST COMPLETE!\n");
  }
