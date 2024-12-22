#include "deal.h"

// Global Tableau variable and a queue from which cards are pulled
Card Tableau[COLUMN_NUMBER][MAX_COLUMN_LENGTH];
Card Queue[CARD_NUMBER];

// Card indicating end of the row
Card End_Card;

// Global dealing variable, points to which card is now to be dealt
int Dealing_Idx;

int Available_Deals = 5;
int Current_Sequence_Length;

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

int get_end_card_index(const int col)
{
    int row = 0;
    Card curr = Tableau[col][row];

    while (curr.value != -1)
    {
        row++;
        curr = Tableau[col][row];
    }
    
    // This is the index of the row that has an end card
    return row;
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

bool stack_deal()
{
    if (Available_Deals == 0)
        return false;
    
    for (int col = 0; col < 10; col++)
    {
        int row = get_end_card_index(col);

        Tableau[col][row] = Queue[Dealing_Idx];
        Dealing_Idx++;
        Tableau[col][row + 1] = End_Card;
    }

    flip_top();
    Available_Deals--;

    return true;
}

void move_cards(int input[])
{
    // Variables holding information about "from" column
    int col_from = input[0] - 1;
    int row_from = input[1] - 1;

    // Index of an end card
    int end_of_from = row_from + Current_Sequence_Length;

    // Variables regarding "to" column
    int col_to = input[2] - 1;
    int end_of_to = get_end_card_index(col_to);
    int row_idx = end_of_to;
    
    // Move the sequence
    for (int idx = 0; idx < Current_Sequence_Length; idx++)
        Tableau[col_to][row_idx + idx] = Tableau[col_from][row_from + idx];
    
    Card curr = Tableau[col_from][row_from];
    while (curr.value > 0)
    {
        // Set to default initialization
        curr.value = 0;
        curr.suit = 0;
        curr.flipped = false;
        curr = Tableau[col_from][row_from + 1];
    }

    // Place an end card at the end of the altered columns
    Tableau[col_to][end_of_to + Current_Sequence_Length] = End_Card;
    Tableau[col_from][row_from] = End_Card;
}