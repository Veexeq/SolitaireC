#include <stdio.h>

// For random numbers
#include <time.h>
#include <stdlib.h>

#define NUMBER_OF_CARDS 104

// Structs
typedef struct Card_Structure
{
    int suit;
    int val;
} Card;

// Prototypes
int mainDeal();
void initialize();
void shuffle();
void displayShuffle();

// Current deal, a global variable
Card CURRENT_DEAL[NUMBER_OF_CARDS];

// MAIN FUNCTION RESPONSIBLE FOR DEALING CARDS //

int mainDeal()
{
    initialize();
    displayShuffle();
    shuffle();
    displayShuffle();

    return 0;
}

// END OF MAIN FUNCTION RESPONSIBLE FOR DEALING CARDS //

void initialize()
{
    int idx = 0;
    Card curr;

    // Taking the second deal into consideration, as number of cards dealt must be exactly NUMBER_OF_CARDS
    while (idx < NUMBER_OF_CARDS)
    {
        for (int suit = 1; suit <= 4; suit++)
        {
            curr.suit = suit;

            for (int val = 1; val <= 13; val++)
            {
                curr.val = val;

                CURRENT_DEAL[idx] = curr;
                idx++;   
            }
        }
    }
}

void shuffle()
{
    // Generate seed
    srand(time(NULL));

    for (int idx = 0; idx < NUMBER_OF_CARDS; idx++)
    {
        Card curr = CURRENT_DEAL[idx];

        int swap_idx = rand() % NUMBER_OF_CARDS;
        Card swap = CURRENT_DEAL[swap_idx];

        Card temp = curr;
        curr = swap;
        swap = temp;
    }
}

void displayShuffle()
{
    for (int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        Card curr = CURRENT_DEAL[i];
        printf("Card number: %d\nCard suit: %d\nCard value: %d\n\n", i, curr.suit, curr.val);
    }
}