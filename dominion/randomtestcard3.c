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
  printf("Testing tribute\n");
  printf("RANDOM TESTS\n");
  for(n=0; n<50; n++){
     int players = (rand() % 50);
     int seed =(rand() % 5000);

     initializeGame(players, k, seed, &G);
     printf("\n--------Running round %d/50--------\n", n+1);
     memcpy(&test, &G, sizeof(struct gameState));
     cardEffect(tribute, choice1, choice2, choice3, &G, handpos, &bonus);

     p = whoseTurn(&test);

     if(G.hand[p][test.handCount[p]-1] != -1)
       printf("Passed where tribute card was added to the players hand\n");
     else
       printf("Failed where tribute card was not added to the players hand\n");


     if(test.playedCardCount+1 == G.playedCardCount)
       printf("Passed where player played tribute card\n");
     else
       printf("Failed where player did not play tribute card\n");


     if(test.discardCount[p] == G.discardCount[p])
       printf("Passed where the tribute was discarded\n");
     else
     {
       printf("Failed where the tribute was not discarded.\n");
     }


     if(test.numActions+2 == G.numActions)
       printf("Passed where an extra action was added\n");
     else
       printf("Failed where an extra action was not added\n");

    }
    printf("\nTEST COMPLETE!\n");
  }
