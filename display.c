#include "display.h"

void print_queue()
{
    for (int i = 0; i < CARD_NUMBER; i++)
    {
        Card curr = Queue[i];
        printf("%d. Queue:\n", i);
        printf("Value: %d\n", curr.value);
        printf("Suit: %d\n\n", curr.suit);
    }
}