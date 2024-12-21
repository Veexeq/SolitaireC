#include <stdio.h>
#include "deal.h"
#include "display.h"
#include "move_validation.h"

int main(void)
{
    // Beginning of the game
    deal_cards();

    // Every move
    while (true)
    {
        display_tableau();

        printf("\n");
        
        int choice[2];
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
            } while (!valid_choice(choice[i]));
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