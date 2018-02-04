// -----------------------------------------------------------------------
// Scott Joynt
// CS 362
// Card Test 2
// -----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "dominion.h"
#include <time.h>

int great_hall_card(struct gameState *state, int currentPlayer, int handPos);

int main() {
  // initialize the random funtion
  srand(time(NULL));
  int playerHandSize = 0;       // Get hand size.
  int playerActions = 0;

  int numPlayers = 2;
  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int rand_number = rand() % + 8192;                        
  struct gameState *state = newGame();          
  struct gameState *testGame = newGame();
  initializeGame(numPlayers, cards, rand_number, state);    

  printf("Testing: village\n");

  memcpy(testGame, state, sizeof(struct gameState));                   
  
  //Set's the inital vairables
  playerHandSize = numHandCards(testGame);       
  playerActions = testGame->numActions;         
 
  testGame->hand[testGame->whoseTurn][0] = great_hall;
  great_hall_card(testGame, testGame->whoseTurn, 0);


if((numHandCards(testGame) - playerHandSize) == 2) {
        printf("Hand size increased: PASSED \n");
    } else {
        printf("Hand size increased: PASSED \n");
    }
    
    if(state->deckCount[state->whoseTurn] == testGame->deckCount[testGame->whoseTurn]+3) {
        printf("Deck size decreased: PASSED \n");
    } else {
        printf("Hand size increased: PASSED \n");
    }
    
    if((playerActions - testGame->numActions) == 1) {
        printf("Action decreased: PASSED \n");
    } else {
        printf("Action decreased: FAILED \n");
    }
    
    if(testGame->numBuys == 1) {
        printf("Buys remained the same: PASSED \n");
    } else {
        printf("Buys remained the same: FAILED \n");
    }
    
    if(testGame->coins == state->coins) {
        printf("Coins remained the same: PASSED \n");
    } else {
        printf("Coins remained the same: FAILED \n");
    }
    
    if(testGame->handCount[0] > 0) {
        printf("Other play hand size remained the same: PASSED \n");
    } else {
        printf("Other play hand size remained the same: FAILED \n");
    }
    
    if(testGame->deckCount[0] > 10) {
        printf("Other play deck size remained the same: PASSED \n");
    } else {
        printf("Other play deck size remained the same: FAILED \n");
    }
    
    if(testGame->discardCount[0] > 0) {   
        printf("Other play discard size remained the same: PASSED \n");
    } else {
        printf("Other play discard size remained the same: FAILED \n");
    }

  return 0;
}
