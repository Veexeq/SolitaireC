#include "move_validation.h"
#include "deal.h"

/*  Return codes:
    -1 : incorrect
    0  : deal
    1  : correct       */
int valid_choice(int input, int part)
{
        // Column part
        if (part != 1)
        {
            if (input >= 1 && input <= 10)
                return 1;
            if (input == 0)
                return 0;
        }

        // Row part
        if (input > 0)
            return 1;
        
        return -1;
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