#include <stdio.h>
#include "deal.h"
#include "display.h"
#include "move_validation.h"

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

        int choice[2];
        int correct = false;

        for (int i = 0; i < 2; i++)
        {
            do
            {
                switch (i)
                {
                case 0:
                    printf("Moving card from column...: ");
                    break;
                case 1:
                    printf("To column...: ");
                    break;
                }
                scanf("%d", &choice[i]);

                correct = valid_choice(choice[i]);
                if (correct == -1)
                    printf("Incorrect column number. Please input 1-10 or 0 in order to deal from the stack.\n");
                else if (correct == 0)
                {
                    // Deal from the stack mechanic to be implemented
                    printf("Dealing cards from the stack...\n");

                    // Mark choice as a deal request
                    choice[0] = -1;
                    choice[1] = -1;

                    // Exit the input loop
                    i = 2;
                    break;
                }
            } while (correct == -1);
        }
        printf("\n");

        // Request for a deal from the stack
        if (choice[0] == -1)
        {
            bool dealt = stack_deal();
            if (!dealt)
                printf("No more deals from the stack available.\n\n");
        }

        // Only for windows terminal
        // system("cls");
    }

    printf("\nPress ENTER to exit the program. ");
    getchar();
    return 0;
}