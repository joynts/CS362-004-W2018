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
    int playerHandSize = 0;
    int playerActions = 0;
    int handSizeIncrease = 0;
    int actionDecrease = 0;
    int smithyHandCount = 0;
    int smithyDiscardCount = 0;
    int smithyPlayedCount = 0;
    int otherHandIncrease = 0;
    int otherDeckIncrease = 0;
    int otherDiscardIncrease = 0;
    
    // set variables for the main function
    int numPlayers = 2;
    int rand_number = rand() % + 8192;
   struct gameState *game_state = newGame();;
    struct gameState *stored_game = newGame();
    int cards[10] = {adventurer, minion, cutpurse, steward, smithy,
        council_room, village, mine, tribute, ambassador};
    
    // set the memory and assert that the game initialized
    memset(&game_state, 128, sizeof(struct gameState));
    assert(initializeGame(numPlayers, cards, rand_number, &game_state) == 0);
    
    printf("Testing: Smity");
    
    memcpy(stored_game, game_state, sizeof(struct gameState));
    playerHandSize = numHandCards(stored_game);       // Get hand size.
    playerActions = stored_game->numActions;          // Get initial action amount.
    
    handSizeIncrease = 0;
    otherHandIncrease = 0;
    otherDeckIncrease = 0;
    otherDiscardIncrease = 0;
    
    // Set player 1's first card in hand to be smithy card.
    stored_game->hand[stored_game->whoseTurn][0] = smithy;
    smithy_card(stored_game, stored_game->whoseTurn, 0);         // First card is smithy;
    
    handSizeIncrease = numHandCards(stored_game) - playerHandSize;       // Find amount players hand size increased by.
    actionDecrease = playerActions - stored_game->numActions;
    
    // See if any other players handsize increased, don't include player that played smithy.
    int i = 0;
    for(i = 1; i < numPlayers; i++) {
        if(stored_game->handCount[i] > 0) {
            otherHandIncrease++;
        }
        if(stored_game->deckCount[i] > 10) {
            otherDeckIncrease++;
        }
        if(stored_game->discardCount[i] > 0) {
            otherDiscardIncrease++;
        }
    }
    
    // Make sure player has no more smithy cards in hand since we only added one to their hand.
    for(i = 0; i < numHandCards(stored_game); i++) {
        if(stored_game->hand[stored_game->whoseTurn][i] == smithy) {        // There is a smithy in hand.
            smithyHandCount++;
        }
    }
    
    // Make sure player has no smithy cards in discard pile.
    for(i = 0; i < stored_game->discardCount[stored_game->whoseTurn]; i++) {
        if(stored_game->discard[stored_game->whoseTurn][i] == smithy) {        // There is a smithy in discard.
            smithyDiscardCount++;
        }
    }
    
    // Make sure player has 1 smithy card in played card pile.
    for(i = 0; i < stored_game->playedCardCount; i++) {
        if(stored_game->playedCards[i] == smithy) {        // There is a smithy in played cards.
            smithyPlayedCount++;
        }
    }
    
    
    if(handSizeIncrease == 2) {
        printf("Hand size increased: PASSED");
    } else {
        printf("Hand size increased: PASSED");
    }
    
    if(game_state->deckCount[game_state->whoseTurn] == stored_game->deckCount[stored_game->whoseTurn]+3) {
        printf("Deck size decreased: PASSED");
    } else {
        printf("Hand size increased: PASSED");
    }
    
    if(actionDecrease == 1) {
        printf("Action decreased: PASSED");
    } else {
        printf("Action decreased: FAILED");
    }
    
    if(stored_game->numBuys == 1) {
        printf("Buys remained the same: PASSED");
    } else {
        printf("Buys remained the same: FAILED");
    }
    
    if(stored_game->coins == game_state->coins) {
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
    
    return 0;
}
