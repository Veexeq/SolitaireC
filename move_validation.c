#include "move_validation.h"
#include "deal.h"

/*  Return codes:
    -1 : incorrect
    0  : deal
    1  : correct       */
int valid_choice(const int SIZE, int input[])
{
    // Request for a deal
    if (input[0] == 0 && input[1] == 0 && input[2] == 0)
        return 0;
    
    // Not a deal request
    // Handle columns first
    if (!( (input[0] >= 1 && input[0] <= 10) && (input[2] >= 1 && input[2] <= 10) ))
        return -1;
    

    // Handle row number
    int row_idx = input[1] - 1;
    int col_idx = input[0] - 1;

    // Get the end card index from the first column
    int end_card_idx = get_end_card_index(col_idx);
    
    if (row_idx < 0 || row_idx >= end_card_idx)
        return -1;

    return 1;
}

/*  Return codes:
    -1 : This sequence cannot be moved
    0  : This sequence stayed in the same place after this move
    1  : This move is correct
*/
int valid_move(int input[])
{
    // Column numbers are the same
    if (input[0] == input[2])
        return 0;

    // Indexes are one number lower due to counting from 0
    int col_from = input[0] - 1;
    int row = input[1] - 1;
    int col_to = input[2] - 1;

    // Length of the sequence to be moved
    int seq_length = 0;

    // Checking whether this sequence can be moved from its place
    Card curr = Tableau[col_from][row];
    if (!curr.flipped)
        return -1;

    int end_card_idx = get_end_card_index(col_from);
    int seq_suit = curr.suit;

    // Used to check if the sequence is descending strictly by one at a time
    int prev_val = curr.value + 1;

    while (curr.value != -1 && curr.suit == seq_suit && (prev_val - curr.value == 1))
    {
        prev_val = curr.value;
        row++;
        seq_length++;
        curr = Tableau[col_from][row];
    }

    if (row != end_card_idx)
        return -1;

    // Handling second part of the move

    // Setting curr to the beginning of the sequence
    curr = Tableau[col_from][row - seq_length];

    // Gather information about the destination of the sequence
    end_card_idx = get_end_card_index(col_to);
    Card go_to = Tableau[col_to][end_card_idx - 1];

    if (curr.value != go_to.value - 1)
        return -1;
    
    // Pass the length to the deal.c
    Current_Sequence_Length = seq_length;

    return 1;
}