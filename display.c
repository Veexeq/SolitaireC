#include "display.h"

// Testing methods (T_...)

void T_print_queue()
{
    for (int i = 0; i < CARD_NUMBER; i++)
    {
        Card curr = Queue[i];
        printf("%d. Queue:\n", i);
        printf("Value: %d\n", curr.value);
        printf("Suit: %d\n\n", curr.suit);
    }
}

void T_display_tableau()
{
    printf("Printing the tableau. Card template: (value, suit)\n");
    
    // max_length defines row number after which everything is "empty"
    int max_length = 0;
    for (int col = 0; col < COLUMN_NUMBER; col++)
    {
        int row_idx = 0;
        Card curr = Tableau[col][row_idx];

        // End Card requirement
        while (curr.value != -1)
        {
            row_idx++;
            curr = Tableau[col][row_idx];
        }

        max_length = fmax(max_length, row_idx);
    }

    // Print the tableau row-by-row up to the pivot
    for (int row = 0; row < max_length; row++)
    {
        for (int col = 0; col < COLUMN_NUMBER; col++)
        {
            Card curr = Tableau[col][row];

            // Do not print empty cards and the end card
            if (!(curr.value <= 0))
                printf("(%d, %d)\t", curr.value, curr.suit);
        }
        printf("\n");
    }
}