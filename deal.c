#include "deal.h"

// Global Tableau variable and a queue from which cards are pulled
Card Tableau[COLUMN_NUMBER][MAX_COLUMN_LENGTH];
Card Queue[CARD_NUMBER];

// Card indicating end of the row
Card End_Card;

// Global dealing variable, points to which card is now to be dealt
int Dealing_Idx;

// Dealing two suits
void deal_cards()
{
    // Initialization, fill the queue with 104 cards
    queue_fill();
    end_card_initialization();

    // Fill the tableau with the first deal: 4*6 + 6*5 = 54 cards
    for (int col = 0; col < 10; col++)
    {
        int cards_in_col = (col < 4) ? 6 : 5;
        for (int row = 0; row < cards_in_col; row++)
        {
            Tableau[col][row] = Queue[Dealing_Idx];
            Dealing_Idx++;
        }

        // Place an end card at the end of the column
        Tableau[col][cards_in_col] = End_Card;
    }

    flip_top();
}

void end_card_initialization()
{
    End_Card.value = -1;
    End_Card.suit = -1;
    End_Card.flipped = false;
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
        curr.value = idx % 13 + 1;
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

void flip_top()
{
    for (int col = 0; col < COLUMN_NUMBER; col++)
    {
        // Find the index of the end card
        int end_idx = 0;
        Card curr = Tableau[col][0];

        while (curr.value > 0)
        {
            end_idx++;
            curr = Tableau[col][end_idx];
        }

        Tableau[col][end_idx - 1].flipped = true;
    }
}