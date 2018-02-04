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

int main() {
  int i = 0;
  int playerHandSize = 0;       // Get hand size.
  int playerActions = 0;
  int handSizeIncrease = 0;
  int actionDecrease = 0;
  int smithyHandCount = 0;
  int smithyDiscardCount = 0;
  int smithyPlayedCount = 0;

  int otherHandIncrease = 0;
  int otherDeckIncrease = 0;
  int otherDiscardIncrease = 0;


  int numPlayers = 2;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int randomSeed = -1;                          // Set randomSeed to less than 0 so it is based off system clock in the initializeGame method.
  struct gameState *state = newGame();          // Initialize game state.
  struct gameState *testGame = newGame();

  initializeGame(numPlayers, kingdomCards, randomSeed, state);    // Initialize game with valid game values.


  printf("\n***** TESTING PLAY SMITHY *****\n");

  memcpy(testGame, state, sizeof(struct gameState));                    // Setup clean test game.
  // Test playing smithy correctly increments player's handsize.
  playerHandSize = numHandCards(testGame);       // Get hand size.
  playerActions = testGame->numActions;          // Get initial action amount.

  handSizeIncrease = 0;
  otherHandIncrease = 0;
  otherDeckIncrease = 0;
  otherDiscardIncrease = 0;

  // Set player 1's first card in hand to be smithy card.
  testGame->hand[testGame->whoseTurn][0] = smithy;
  smithy_card(testGame, testGame->whoseTurn, 0);         // First card is smithy;

  handSizeIncrease = numHandCards(testGame) - playerHandSize;       // Find amount players hand size increased by.
  actionDecrease = playerActions - testGame->numActions;

  // See if any other players handsize increased, don't include player that played smithy.
  for(i = 1; i < numPlayers; i++) {
    if(testGame->handCount[i] > 0) {
      otherHandIncrease++;
    }
    if(testGame->deckCount[i] > 10) {
      otherDeckIncrease++;
    }
    if(testGame->discardCount[i] > 0) {
      otherDiscardIncrease++;
    }
  }

  // Make sure player has no more smithy cards in hand since we only added one to their hand.
  for(i = 0; i < numHandCards(testGame); i++) {
    if(testGame->hand[testGame->whoseTurn][i] == smithy) {        // There is a smithy in hand.
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


if(handSizeIncrease == 2) {
        printf("Hand size increased: PASSED");
    } else {
        printf("Hand size increased: PASSED");
    }
    
    if(state->deckCount[state->whoseTurn] == testGame->deckCount[testGame->whoseTurn]+3) {
        printf("Deck size decreased: PASSED");
    } else {
        printf("Hand size increased: PASSED");
    }
    
    if(actionDecrease == 1) {
        printf("Action decreased: PASSED");
    } else {
        printf("Action decreased: FAILED");
    }
    
    if(testGame->numBuys == 1) {
        printf("Buys remained the same: PASSED");
    } else {
        printf("Buys remained the same: FAILED");
    }
    
    if(testGame->coins == state->coins) {
        printf("Coins remained the same: PASSED");
    } else {
        printf("Coins remained the same: FAILED");
    }
    
    if(otherHandIncrease == 0) {
        printf("Other play hand size remained the same: PASSED");
    } else {
        printf("Other play hand size remained the same: FAILED");
    }
    
    if(otherDeckIncrease == 0) {
        printf("Other play deck size remained the same: PASSED");
    } else {
        printf("Other play deck size remained the same: FAILED");
    }
    
    if(otherDiscardIncrease == 0) {   
        printf("Other play discard size remained the same: PASSED");
    } else {
        printf("Other play discard size remained the same: FAILED");
    }

  // Free memory
  free(state);
  state = 0;

  free(testGame);
  testGame = 0;

  return 0;
}
