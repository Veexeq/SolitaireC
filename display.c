#include "display.h"

// Testing methods are marked with 'T_' (T_...)

void display_main_menu()
{
    printf("=== SPIDER SOLITAIRE ===\n");
    printf("1. Start new game\n");
    printf("2. Resume previous game\n");
    printf("3. Your stats\n");
    printf("4. About\n");
    printf("5. Exit\n\n");
    
    bool correct = false;
    int choice;
    do
    {
        printf("Type your choice number: ");
        scanf("%d", &choice);

        if (!(choice >= 1 && choice <= 5))
            printf("Your choice is incorrect. Type number 1-5.\n");
        else
            correct = true;
        
    } while (!correct);
    
    switch (choice)
    {
    case 1:
        // Exiting this method <=> progressing further in main()
        // system("cls");
        return;
        break;
        // Other cases are to be developed
    }
}

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

int find_max_length()
{
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

    return max_length;
}

void T_display_tableau()
{
    printf("Printing the tableau. Card template: (value, suit)\n");
    
    // max_length defines row number after which everything is "empty"
    int max_length = find_max_length();

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

void display_tableau()
{
    const int STACK_OFFSET = 55;

    // max_length defines row number after which everything is "empty"
    int max_length = find_max_length();

    // Print the tableau row-by-row up to the pivot
    for (int row = 0; row < max_length; row++)
    {
        for (int col = 0; col < COLUMN_NUMBER; col++)
        {
            Card curr = Tableau[col][row];

            // Do not print empty cards and the end card
            if (!(curr.value <= 0))
            {
                if (!curr.flipped)
                    printf("(X, X)\t");
                else
                    printf("(%d, %d)\t", curr.value, curr.suit);
            }
        }
        printf("\n");
    }
    printf("\n%*cAvaliable deals: [%d]\n", STACK_OFFSET, ' ', Available_Deals);
}