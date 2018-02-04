// -----------------------------------------------------------------------
// Scott Joynt
// CS 362
// Unit Test 2
// -----------------------------------------------------------------------

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
    
    // set variables for the main function
    int numPlayers = 2;
    int rand_number = rand() % + 8192;
    struct gameState game_state, stored_game;
    int cards[10] = {adventurer, minion, cutpurse, steward, smithy,
        council_room, village, mine, tribute, ambassador};
    int compare;
    // set the memory and assert that the game initialized
    memset(&game_state, 128, sizeof(struct gameState));
    assert(initializeGame(numPlayers, cards, rand_number, &game_state) == 0);

    printf ("Begin shuffle() testing:\n");
    
    memcpy(&stored_game, &game_state, sizeof(struct gameState));
    
    int j = 0;
    for (j = 0; j < numPlayers; j++){
        
        printf("Test for Player %d", j + 1);
        shuffle(thisPlayer, &game_state);
 
        assert(stored_game.deckCount[0] == game_state.deckCount[0]);
    
        int i = 0;
        for (i = 0; i < stored_game.deckCount[0]; i++) {
            if (stored_game.deck[0][i] == game_state.deck[0][i])
            {
                printf("Equals %d, %d\n", stored_game.deck[0][i], game_state.deck[0][i]);
                compare++;
            }
            else{
                printf("Not Equal %d, %d\n", stored_game.deck[0][i], game_state.deck[0][i]);
            }
        }
        assert(compare != game_state.deckCount[0]);
    }
    printf ("Test passed\n");
    
    return 0;
}
