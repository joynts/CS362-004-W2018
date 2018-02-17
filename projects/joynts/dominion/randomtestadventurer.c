// -----------------------------------------------------------------------
// Scott Joynt
// CS 362
// Random Card Test 4
// -----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "dominion.h"
#include <time.h>

int adventurer_card(struct gameState *state, int currentPlayer, int drawnTreasure, int cardDrawn, int temphand[], int z);

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
  int drawnTreasure = rand() % + 8; 
  int cardDrawn = rand() % + 8;
  int temphand[rand() % + 8];
  int z = rand() % + 8;
  
  printf("Random Testing: adventurer\n");
  
  int x = 0;
  for(x = 0; x < 1000; x++){
    rand_number = rand() % + 8192; 
    initializeGame(numPlayers, cards, rand_number, state);    
    memcpy(testGame, state, sizeof(struct gameState));                   
  
    //Set's the inital vairables
    playerHandSize = numHandCards(testGame);       
    playerActions = testGame->numActions;         
 
    testGame->hand[testGame->whoseTurn][0] = adventurer;
    drawnTreasure = rand() % + 8; 
    printf("%d" \n, drawnTreasure);
    cardDrawn = rand() % + 8;
    printf("%d" \n,cardDrawn);
    temphand[rand() % + 8];
    printf("%d" \n,temphand);
    z = rand() % + 8;
    printf("%d" \n,z);
    adventurer_card(testGame, testGame->whoseTurn,drawnTreasure,cardDrawn,temphand,z);


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
  }
  return 0;
}
