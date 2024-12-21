#ifndef DEAL_H
#define DEAL_H

#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Preprocessor directives

// From the rules of spider solitaire
#define CARD_NUMBER 104
#define MAX_COLUMN_LENGTH 78
#define COLUMN_NUMBER 10

// Structs, typedefs

/*
Two suits: 0 - hearts; 1 - spades
Values like in solitaire sequences: 0 - Ace, 1 - (2), 2 - (3) ... 10 - Jack, 11 - Queen, 12 - King
*/
typedef struct Card_Struct
{
    int suit;
    int value;
    bool flipped;
} Card;

// Prototypes 
bool deal_cards();
void queue_fill();

// Externs
extern Card Tableau[COLUMN_NUMBER][MAX_COLUMN_LENGTH];
extern Card Queue[CARD_NUMBER]; 

#endif