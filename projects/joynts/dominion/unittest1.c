// Scott Joynt
// CS 362
// Unit Test 1 getCost()
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int getDominionCardCost(int i);
//Return the cost of card i

int main() {
    
    // initialize the random funtion
    srand(time(NULL));
    // load the card array
    int cards[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    // Other Variables
    struct gameState game_state;
    int numPlayers = 2;
    int rand_number = rand() % + 8192;
    int rand_hand;
    int rand_deck;
    int rand_card;
    
    printf ("Testing the funtion of getCost().\n");
    
    int i = 0;
    for (i = 0; i < numPlayers; i++)
    {
        // set the memory and assert that the game initialized
        memset(&game_state, 128, sizeof(struct gameState));
        assert(initializeGame(numPlayers, cards, rand_number, &game_state) == 0);
        
        // hand card test
        printf("Player %d hand card cost\n", i );
        rand_hand = rand() % MAX_HAND;
        game_state.handCount[i] = rand_hand;
        
        int j = 0;
        for (j = 0; j < rand_hand; j++)
        {
            rand_card = rand() % 64;
            game_state.hand[i][j] = rand_card;
            assert(getCost(game_state.hand[i][j]) == getDominionCardCost(randomCard));
        }
        
        // deck card test
        printf("Player %d deck card cost\n", i );
        rand_deck = rand() % MAX_DECK;
        game_state.deckCount[i] = rand_deck;
        
        for (j = 0; j < rand_deck; j++)
        {
            rand_card = rand() % 64;
            game_state.deck[i][j] = rand_card;
            assert(getCost(G.deck[i][j]) == getDominionCardCost(randomCard));
        }
        
    }
    // print passed statement
    printf("The Function getCost Passed.\n");
    return 0;
}

// gets the really
int getDominionCardCost(int i)
{
    switch(i){
        case(curse):
            return 0;
        case(estate):
            return 2;
        case(duchy):
            return 5;
        case(province):
            return 8;
        case(copper):
            return 0;
        case(silver):
            return 3;
        case(gold):
            return 6;
        case(adventurer):
            return 6;
        case(council_room):
            return 5;
        case(feast):
            return 4;
        case(gardens):
            return 4;
        case(mine):
            return 5;
        case(remodel):
            return 4;
        case(smithy):
            return 4;
        case(village):
            return 3;
        case(baron):
            return 4;
        case(great_hall):
            return 3;
        case(minion):
            return 5;
        case(steward):
            return 3;
        case(tribute):
            return 5;
        case(ambassador):
            return 3;
        case(cutpurse):
            return 4;
        case(embargo):
            return 2;
        case(outpost):
            return 5;
        case(salvager):
            return 4;
        case(sea_hag):
            return 4;
        case(treasure_map):
            return 4;
        default:
            return -1;
        }
}
