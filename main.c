#include <stdio.h>
#include "deal.h"
#include "display.h"
#include "move_validation.h"

int main(void)
{
    // Main menu part
    display_main_menu();

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
                    // Exit the input loop
                    printf("Dealing cards from the stack...\n");
                    i = 2;
                    break;
                }
            } while (correct == -1);
        }
        printf("\n");

        printf("%d %d\n", choice[0], choice[1]);

        // Only for windows terminal
        // system("cls");
    }

    printf("\nPress ENTER to exit the program. ");
    getchar();
    return 0;
}