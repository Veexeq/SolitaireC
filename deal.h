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

/*  Two suits: 0 - hearts; 1 - spades
    Values like in solitaire sequences: 1 - Ace, 2 - (2), 3 - (3) ... 11 - Jack, 12 - Queen, 13 - King  */
typedef struct Card_Struct
{
    int suit;
    int value;
    bool flipped;
} Card;

// Prototypes 
void deal_cards();
void queue_fill();
void end_card_initialization();
void flip_top();

// Externs
extern Card Tableau[COLUMN_NUMBER][MAX_COLUMN_LENGTH];
extern Card Queue[CARD_NUMBER]; 
extern Card End_Card;

extern int Available_Deals;

#endif