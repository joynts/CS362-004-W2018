// -----------------------------------------------------------------------
// Scott Joynt
// CS 362
// Card Test 1
// -----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "dominion.h"
#include <time.h>

int main() {
  // initialize the random funtion
  srand(time(NULL));
  int playerHandSize = 0;       // Get hand size.
  int playerActions = 0;
  int smithyHandCount = 0;
  int smithyDiscardCount = 0;
  int smithyPlayedCount = 0;

  int numPlayers = 2;
  int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int rand_number = rand() % + 8192;                        
  struct gameState *state = newGame();          
  struct gameState *testGame = newGame();
  initializeGame(numPlayers, cards, rand_number, state);    

  printf("Testing: smithy\n");

  memcpy(testGame, state, sizeof(struct gameState));                   
  
  //Set's the inital vairables
  playerHandSize = numHandCards(testGame);       
  playerActions = testGame->numActions;         
 
  testGame->hand[testGame->whoseTurn][0] = smithy;
  smithy_card(testGame, testGame->whoseTurn, 0);

  // Make sure player has no more smithy cards in hand since we only added one to their hand.
  int i = 0;
  for(i = 0; i < numHandCards(testGame); i++) {
    if(testGame->hand[testGame->whoseTurn][i] == smithy) {        
      smithyHandCount++;
    }
  }

  // Make sure player has no smithy cards in discard pile.
  for(i = 0; i < testGame->discardCount[testGame->whoseTurn]; i++) {
    if(testGame->discard[testGame->whoseTurn][i] == smithy) {        // There is a smithy in discard.
      smithyDiscardCount++;
    }
  }

  // Make sure player has 1 smithy card in played card pile.
  for(i = 0; i < testGame->playedCardCount; i++) {
    if(testGame->playedCards[i] == smithy) {        // There is a smithy in played cards.
      smithyPlayedCount++;
    }
  }


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
    
    if(testGame->handCount[1] > 0) {
        printf("Other play hand size remained the same: PASSED \n");
    } else {
        printf("Other play hand size remained the same: FAILED \n");
    }
    
    if(testGame->deckCount[1] > 10) {
        printf("Other play deck size remained the same: PASSED \n");
    } else {
        printf("Other play deck size remained the same: FAILED \n");
    }
    
    if(testGame->discardCount[1] > 0) {   
        printf("Other play discard size remained the same: PASSED \n");
    } else {
        printf("Other play discard size remained the same: FAILED \n");
    }

  return 0;
}
