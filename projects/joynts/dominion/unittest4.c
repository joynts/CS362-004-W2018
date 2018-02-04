// -----------------------------------------------------------------------
// Scott Joynt
// CS 362
// Unit Test 4
// -----------------------------------------------------------------------

#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){
    // set variables for the main function
    int numPlayers = 2;
    struct gameState game_state, stored_game;
    int rand_number = rand() % + 8192;
    int cards[10] = {adventurer, minion, cutpurse, steward, smithy,
        council_room, village, mine, tribute, ambassador};
    
    // set the memory and assert that the game initialized
    memset(&game_state, 128, sizeof(struct gameState));
    assert(initializeGame(numPlayers, cards, rand_number, &game_state) == 0);
    
    
    printf ("Begin shuffle() testing:\n");
    int k = 0;
    for(k = 0; k < numPlayers; k++){
       printf("Test for Player %d \n", k + 1);
        int i = 0;
        for(i = 0; i < treasure_map + 1; i++){
            game_state.supplyCount[i] = -1;
        }
    
        game_state.supplyCount[province] = 0;
        memcpy(&stored_game, &game_state, sizeof(struct gameState));
    
        // check when a providence is removed
        if(isGameOver(&game_state) == 1){
            printf("No provideces available: PASSED\n");
        }
        else{
            printf("No provideces available: FAILED\n");
        }
    
        // check game state
        if(memcmp(&stored_game, &game_state, sizeof(struct gameState)) == 0){
            printf("Providence games state: PASSED\n");
        }
        else{
            printf("Providence games state: PASSED\n");
        }
        
        game_state.supplyCount[province] = 1;
    
        int j = 0;
        for( j = 0; j < 3; j++){
            game_state.supplyCount[j] = 0;
        }
    
        memcpy(&stored_game, &game_state, sizeof(struct gameState));
    
        if(isGameOver(&game_state) == 1){
            printf("First Three card are empty: PASSED\n");
        }
        else{
            printf("First Three card are empty: FAILED\n");
        }
    
        // make sure that game state hasn't changed
        if(memcmp(&stored_game, &game_state, sizeof(struct gameState)) == 0){
            printf("Card game state: PASSED\n");
        }
        else{
            printf("Card game state: FAILED\n");
        }
        int last = province;
        game_state.supplyCount[2] = -1;
    
    
    
        while(last < treasure_map -1){
            game_state.supplyCount[++last] = 0;
            memcpy(&stored_game, &game_state, sizeof(struct gameState));
            if(isGameOver(&game_state) == 1){
                printf("Treasure_map 3 cards: PASSED\n");
            }
            else{
                printf("Treasure_map 3 cards: FAILED\n");
            }
            // make sure game state is the same
            if(memcmp(&stored_game, &game_state, sizeof(struct gameState)) == 0){
                printf("Card game state: PASSED\n");
            }
            else{
                printf("Card game state: FAILED\n");
            }
            
            game_state.supplyCount[last] = -1;
        }
    }
    printf("All tests passed!\n");
    return 0;
}
