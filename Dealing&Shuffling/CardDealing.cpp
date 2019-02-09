#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);

int main()
{
  //initialise suit array
  const char *suit[4]={"Hearts","Diamonds","CLubs","Spades"};

  //initialise face array
  const char *face[13]={"Ace", "Two","Three","Four",
                        "Five","Six","Seven","Eight",
                        "Nine","Ten","Jack","Queen","King"};

  //initialise deck array
  int deck[4][13]={0};

  //Random num gen
  srand(time(0));

  //Calling functions
  shuffle(deck);
  deal(deck,face,suit);

  return 0;
}
//SHuffle cards in deck
void shuffle(int wDeck[][13])
{
  int row; //row number
  int column; //column number
  int card; //counter

  //For each of the 52 cards , choose randomly inside the 52 card deck
  for (card = 1; card <= 52; card++) {
    do {
      row=rand() % 4;
    } while(wDeck[row][column] !=0);
  }

  //place card number in chosen slot of deck
  wDeck[row][column]=card;
}//ENd function shuffle()


void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
  int card;
  int row;
  int column;

  //deal each of the 52 cards
  for (card = 1; card <= 52; card++) {
    //loop through rows
    for (row = 0; row <= 3; row++) {
      //loop through columns
      for (column= 0; column <= 12; column++) {
        // display card
        if (wDeck[row][column]==card) {
          printf("%5s of %-8s %c",wFace[column], wSuit[row], card % 2 ==0 ? '\n' :'\t' );
        }
      }
    }
  }
}//end function deal()
