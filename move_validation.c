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

bool valid_move(int start_column, int start_row, int to_column)
{
    // This move doesn't change anything
    if (start_column == to_column)
        return true;
    
    // Checking 'from' location
    // 1. All suits must be the same
    // 2. All cards must be in a sequence one rank apart
    bool suit_criteria = true;
    bool seq_criteria = true;

    return true;
}