#include <stdio.h>
#include "deal.h"
#include "display.h"

int main(void)
{
    deal_cards();
    T_display_tableau();
 
    printf("\nPress any key to exit the program. ");
    getchar();
    return 0;
}