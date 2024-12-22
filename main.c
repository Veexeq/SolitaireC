#include <stdio.h>
#include "deal.h"
#include "display.h"
#include "move_validation.h"

#define INPUT_SIZE 3

int main(void)
{
    // Main menu part
    // display_main_menu();

    // Beginning of the game
    deal_cards();

    // Every move
    while (true)
    {
        display_tableau();
        printf("\n");

        int validation_code = -1;
        int choice[INPUT_SIZE];

        do
        {
            // First column - Row number - Second column
            printf("Make your move: ");
            scanf("%d %d %d", choice, choice + 1, choice + 2);

            validation_code = valid_choice(INPUT_SIZE, choice);
            if (validation_code == -1)
                printf("Incorrect input. Type: 'column row column' \n");

        } while (validation_code == -1);

        // Handle deal from the stack request
        if (validation_code == 0)
        {
            if (!stack_deal())
                printf("You have no more deals from the stack.\n");

            // Ask for another input
            printf("\n");
            continue;
        }
        
        // Handle correct moves
        printf("\n");

        // Only for windows terminal
        // system("cls");
    }

    printf("\nPress ENTER to exit the program. ");
    getchar();
    return 0;
}