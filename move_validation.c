#include "move_validation.h"

/*  Return codes:
    -1 : incorrect
    0  : deal
    1  : correct       */
int valid_choice(int input)
{
        if (input >= 1 && input <= 10)
            return 1;
        if (input == 0)
            return 0;
        return -1;
}