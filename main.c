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

    /* -1 : game over
        0 : game is still on
        1 : won the game    */
    int end_game = 0;

    // User's input
    int choice[INPUT_SIZE];

    // Every move
    while (end_game == 0)
    {
        display_tableau();
        printf("\n");

        int validation_code = -1;

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
        printf("\n");

        // Handle correct moves
        int valid_code = valid_move(choice);
        switch (valid_code)
        {
        case -1:
            printf("This move is illegal. You cannot move this sequence.\n\n");
            break;
        
        case 0:
            printf("This move doesn't alter the tableau.\n\n");
            break;
        }

        // Only for windows terminal
        // system("cls");
    }

    printf("\nPress ENTER to exit the program. ");
    getchar();
    return 0;
}