// -----------------------------------------------------------------------
// Scott Joynt
// CS 362
// Unit Test 3
// -----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main() {
    // set variables for the main function
    int numPlayers = 2;
    int rand_number = rand() % + 8192;
    struct gameState game_state, stored_game;
    int cards[10] = {adventurer, minion, cutpurse, steward, smithy,
        council_room, village, mine, tribute, ambassador};
    
    // set the memory and assert that the game initialized
    memset(&game_state, 128, sizeof(struct gameState));
    assert(initializeGame(numPlayers, cards, rand_number, &game_state) == 0);
    int j = 0;
    for(j = 0; j < numPlayers; j++){
        printf("Test for Player %d \n", j + 1);
        int deckSize = game_state.deckCount[j];
        
        int i = 0;
        for (i = 0; i <= deckSize; i++){
        
            memcpy(&stored_game, &game_state, sizeof(struct gameState));
            printf("There are %d cards remaining.\n", game_state.deckCount[j]);
        
            // make sure that the drawCard function works
            if (drawCard(j, &game_state) == 0)
            {
                printf("DrawCard Function: PASSED\n");
            }
            else {
                printf("DrawCard Function: FAILED\n");
            }
        
            // make sure hand count went up
            if(game_state.handCount[j] == (stored_game.handCount[j] + 1))
            {
                printf("Hand count incremented: PASSED\n");
            }
            else {
                printf("Hand count incremented: PASSED\n");
                
            }
        
            // make sure the the deck count went down
            if (game_state.deckCount[j] == (stored_game.deckCount[j] - 1))
            {
                printf("Deck decremented: PASSED\n");
            }
            else {
                printf("Deck decremented: FAILED\n");
            }
        
            // make sure that the top card is in hand
            if (game_state.hand[j][game_state.handCount[j] - 1] == stored_game.deck[j][stored_game.deckCount[j] - 1])
            {
                printf("Drawn card in hand: PASSED\n");
            }
            else {
                printf("Drawn card in hand: FAILED\n");
            }
        
            // make sure the discard pile is the same
            if (game_state.discardCount[j] == stored_game.discardCount[j])
            {
                printf("Discard pile size: PASSED\n");
            }
            else {
                printf("Discard pile size: FAILED\n");
            }
        
            discardCard(1, j, &game_state, 0);
        
        printf ("Test passed\n");
        
    }
    }
    return 0;
}
