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
  srand(time(NULL));
  int count1 = 0;
  int count2 = 0;
  int i, n, r, p, handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron,great_hall};

  struct gameState G, test;
  printf("Testing baron\n");
  printf("RANDOM TESTS\n");
  for(n=0; n<50; n++){
     int players = (rand() % 50);
     int seed =(rand() % 5000);

     initializeGame(players, k, seed, &G);
     printf("\n--------Running round %d/50--------\n", n+1);
     memcpy(&test, &G, sizeof(struct gameState));
     cardEffect(baron, choice1, choice2, choice3, &G, handpos, &bonus);

     p = whoseTurn(&test);

     if(G.hand[p][test.handCount[p]-1] != -1)
       printf("Passed where Baron card was added to the players hand\n");
     else
       printf("Failed where Baron card was not added to the players hand\n");


     if(test.playedCardCount+1 == G.playedCardCount)
       printf("Passed where player played Baron card\n");
     else
       printf("Failed where player did not play Baron card\n");


     if(test.discardCount[p] == G.discardCount[p])
       printf("Passed where the Baron was discarded\n");
     else
     {
       printf("Failed where the Baron was not discarded.\n");
     }

     for (i = 0; i < G.handCount[0]; i++)
       {
           if(G.hand[0][i] = estate);
   			count1++;
       }

   	for (i = 0; i < test.handCount[0]; i++)
       {
           if(test.hand[0][i] = estate);
   			count2++;
       }

   	if(count1 == count2-1)
       if(test.coins +4 ==G.coins){
   		    printf("Passed where there is no variance in estate cards\n");
           printf("Passed where the coins is alrady add\n");
       }
       else{
         printf("Failed where the coins is not add\n");
       }
     else
   		printf("Failed where there is a variance in estate cards\n");


     if(test.numActions == G.numActions)
       printf("Passed where an extra action was added\n");
     else
       printf("Failed where an extra action was not added\n");

    }
    printf("\nTEST COMPLETE!\n");
  }
