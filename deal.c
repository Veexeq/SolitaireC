#include "deal.h"

// Global Tableau variable and a queue from which cards are pulled
Card Tableau[COLUMN_NUMBER][MAX_COLUMN_LENGTH];
Card Queue[CARD_NUMBER];

// Dealing two suits
bool deal_cards()
{
    // Initialization, fill the queue with 104 cards
    queue_fill();
    
    return true;
}

void queue_fill()
{
    // Random seed setup
    srand(time(NULL));

    int idx = 0;

    // Populate the queue with cards in order
    while (idx < CARD_NUMBER)
    {
        Card curr;
        curr.value = idx % 13;
        curr.suit = idx / 52;
        curr.flipped = false;

        Queue[idx] = curr;

        idx++;
    } 

    idx = 0;
    int go_to_idx = 0;

    // Shuffle them
    while (idx < CARD_NUMBER)
    {
        go_to_idx = rand() % CARD_NUMBER;

        Card temp = Queue[idx];
        Queue[idx] = Queue[go_to_idx];
        Queue[go_to_idx] = temp;

        idx++;
    }
}
