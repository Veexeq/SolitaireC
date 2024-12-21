#include "move_validation.h"

bool valid_choice(int input)
{
        if (input >= 0 && input <= 10)
            return true;
        return false;
}