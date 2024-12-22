#include "deal.h"
#include "display.h"

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

    Available_Deals--;

    return true;
}

void move_cards(int input[])
{
    // "From" column
    int col_from = input[0] - 1;
    int row_from = input[1] - 1;
    int end_card_from = row_from + Current_Sequence_Length;

    // "To" column
    int col_to = input[2] - 1;
    int end_card_to = get_end_card_index(col_to);
    int row_to = end_card_to - 1;
    
    // Move card to "to"
    for (int i = 0; i < Current_Sequence_Length; i++)
        Tableau[col_to][end_card_to + i] = Tableau[col_from][row_from + i];

    Tableau[col_to][end_card_to + Current_Sequence_Length] = End_Card;
    Tableau[col_from][row_from] = End_Card;

    for (int i = 1; i <= Current_Sequence_Length; i++)
    {
        Card curr = Tableau[col_from][row_from + i];
        curr.value = 0;
        curr.suit = 0;
        curr.flipped = false;
    }
}