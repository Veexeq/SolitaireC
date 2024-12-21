#include <stdio.h>
#include "deal.h"
#include "display.h"

int main(void)
{
    deal_cards();
    display_tableau();
 
    printf("\nPress ENTER to exit the program. ");
    getchar();
    return 0;
}