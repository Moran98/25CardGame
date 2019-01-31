#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//CONSTANTS
#define PLAYING_DECK 52
#define MAX_CARDS_IN_HAND 5
#define FACE_NUM 13
#define SUIT_NUM 4
#define WINNER_SCORE 25

//Global variables
int numOfPlayers;
char face[13][10];
char suit[4][10];
char trumpCard[10][10];
int cardValue;
int i;
int gameOption;
int playerCount;
int cardPicked;
int playerPoints;

//Initialising
i = 0;
playerCount = 0;
playerScore = 0;

FILE*gameHistory;

//FUNCTIONS
void choiceScreen();
void createGame();
void exitGame();
void createDeck();
void handsDealt();
void gameRules();
void roundPoints();

//STRUCTURES
typedef struct 
{
	int cardAmount;
	int playerScore;
	int cardValue[13];
	char cardFace[13][10];
	char cardSuit[13][10];
	char cardPicked[13][10];
}player;


int main()
{
	//Choice Screen decides wether New Game / Continue Saved Game / Exit Game
	choiceScreen();
}

void choiceScreen()
{

	//clear screen
	system("@cls||clear");

	printf("===========================================================================\n");
	printf("         Welcome to Twenty Five !					  |\n");
	printf("===========================================================================\n");

	//initial user prompt
	printf("\n\nPlease decide an action : \n\n");
	printf("1|New Game|   2|Continue|   3|Exit Game| : ");
	scanf("%d", &gameOption);

	//While loop for game mode option/selection
	while (gameOption > 4 || gameOption < 1)
	{
		printf("\n==========\n");
		printf("Nice try!");
		printf("\n==========\n\n");

		printf("1|New Game|   2|Continue|   3|Exit Game|	4|Learn Rules|: ");
		scanf("%d", &gameOption);
	}

	switch (gameOption)
	{
	case 1: //New Game
		createGame();
		//playGame();
		break;
	case 2: //Load up a game
		break;
	case 3: //Exit Game
		exitGame();
		break;
	default:
		break;
	}
}

void createGame()
{
	//Creating game history file
	gameHistory = fopen("gameHistory.txt", "a");

	fprintf(gameHistory, "===========================================================================\n");
	fprintf(gameHistory,"You have started a new game of 25!			                  |\n");
	fprintf(gameHistory,"===========================================================================\n");

	fclose(gameHistory);


	//FUNCTION VARIABLES
	int playerCount;
	char playerName;

	//clear screen
	system("@cls||clear");

	//initial user prompt
	printf("===========================================================================\n");
	printf("You have started a new game of 25!			                  |\n");
	printf("===========================================================================\n");
	printf("\nPlease enter the amount of players that will be playing : Recommeneded (2-6) : ");
	scanf("%d", &numOfPlayers);

	//while to ensure player chooses between 2-6 players
	while (numOfPlayers < 2 || numOfPlayers >6)
	{
		printf("\nUnable to play with this amount of players, Try Again.");
		printf("\nPlease enter the amount of players that will be playing : Recommeneded (2-6) : ");
		scanf("%d", &numOfPlayers);
	}//end while

	//re-inisialising playerCount to 0
	playerCount = 0;

	//call handsDealt function
	handsDealt();
}

void exitGame()
{
	//clear screen
	system("@cls||clear");

	printf("===========================================================================\n");
	printf("         Thank you for playing Twenty Five !			          |\n");
	printf("===========================================================================\n");

	printf("\n\n===========================================================================\n");
	printf("Project was done by Aaron Moran - G00356519                               |\n");
	printf("===========================================================================\n");
}

void handsDealt()
{
	//FUNCTION VARIABLES
	int playerCount;
	int random1, random2;
	int playerScore = 0;
	int numCardInHand;
	int cardCount;
	int roundCount = 0;
	char picked[13];
	player player[6];

	//clear screen
	system("@cls||clear");

	//While to keep gaming going through rounds until player reaches score of 25
	while (playerScore != WINNER_SCORE)
	{
		
		//call deck function
		createDeck();

		for (int i = 0; i < numOfPlayers; i++)
		{
			//for loop
			//DEALS 5 CARDS TO PLAYERS HANDS
			for (int j = 0; j < 5; j++)
			{
				//prints 5 cards to players hands
				player[i].cardAmount = MAX_CARDS_IN_HAND;

				//Switch - Creating random for SUIT CARDS
				random1 = rand() % 4;

				//Overwriting suit values into cardSuit to gen randoms
				switch (random1)
				{
				case 0:
					strcpy(player[i].cardSuit[j], suit[0]);
					break;
				case 1:
					strcpy(player[i].cardSuit[j], suit[1]);
					break;
				case 2:
					strcpy(player[i].cardSuit[j], suit[2]);
					break;
				case 3:
					strcpy(player[i].cardSuit[j], suit[3]);
					break;
				}


				//Switch - Creating random for FACE CARDS
				random2 = rand() % 13;

				//Overwriting face values into cardFace to gen randoms
				switch (random2)
				{
				case 0:
					strcpy(player[i].cardFace[j], face[0]);
					break;
				case 1:
					strcpy(player[i].cardFace[j], face[1]);
					break;
				case 2:
					strcpy(player[i].cardFace[j], face[2]);
					break;
				case 3:
					strcpy(player[i].cardFace[j], face[3]);
					break;
				case 4:
					strcpy(player[i].cardFace[j], face[4]);
					break;
				case 5:
					strcpy(player[i].cardFace[j], face[5]);
					break;
				case 6:
					strcpy(player[i].cardFace[j], face[6]);
					break;
				case 7:
					strcpy(player[i].cardFace[j], face[7]);
					break;
				case 8:
					strcpy(player[i].cardFace[j], face[8]);
					break;
				case 9:
					strcpy(player[i].cardFace[j], face[9]);
					break;
				case 10:
					strcpy(player[i].cardFace[j], face[10]);
					break;
				case 11:
					strcpy(player[i].cardFace[j], face[11]);
					break;
				case 12:
					strcpy(player[i].cardFace[j], face[12]);
					break;


				} // switch
			} // end of nested for
		} //end of for

		//round counter
		roundCount++;

		//Saving UI to file
		gameHistory = fopen("gameHistory.txt", "a");
		fprintf(gameHistory,"\n\nWelcome to Round %d\n", roundCount);
		fprintf(gameHistory,"==========================\n");
		fprintf(gameHistory,"The hands have been dealt.\n");
		fprintf(gameHistory,"==========================\n\n");


		//Round intro UI
		printf("\n\nWelcome to Round %d\n", roundCount);
		printf("==========================\n");
		printf("The hands have been dealt.\n");
		printf("==========================\n\n");

		//printf("The TRUMP card is : %s of %s", player[i].cardFace, player[i].cardSuit);

		//IMPLEMENTS RULES INTO THE GAME
		gameRules();


		//initialise player count to 0
		playerCount = 0;
		cardCount = 0;
		playerScore = 0;
		numCardInHand = 0;


		//For loop displaying hands
		for (i = 0; i < numOfPlayers; i++)
		{
			//PLAYER NUMBER AND HANDS DEALT
			playerCount++;

			fprintf(gameHistory, "\nPlayer %d Hand\n", playerCount);
			fprintf(gameHistory, "-------------\n");
			printf("\nPlayer %d Hand\n", playerCount);
			printf("-------------\n");

			//re-inisialising numCardInHand for each player
			numCardInHand = 0;

			for (int j = 0; j < player[i].cardAmount; j++)
			{
				numCardInHand++;
				fprintf(gameHistory, "%d) %-2s of %-8s\n", numCardInHand, player[i].cardFace[j], player[i].cardSuit[j]);
				printf("%d) %-2s of %-8s\n", numCardInHand, player[i].cardFace[j], player[i].cardSuit[j]);

			} //end of nested for
		}

		//re-inisialising the playerCount to 0
		playerCount = 0;

		//For loop to card selection
		for (int i = 0; i < numOfPlayers; i++)
		{
			playerCount++;
			
			//Initial prompt
			printf("\n=====================================================================");
			printf("\nPlayer %d please select the card you wish to play - (EG 1,2,3,4,5) : ", playerCount);
			scanf("%d", &cardPicked);

			//While loop for the player to choose a card - Must be within 1-5
			while (cardPicked>5||cardPicked<1)
			{

				printf("\nThat card is not in your hand please chose a card 1 to 5. Try Again.\n");


				printf("\n=====================================================================");
				printf("\nPlayer %d please select the card you wish to play - (EG 1,2,3,4,5) : ", playerCount);
				scanf("%d", &cardPicked);
			}

			//Determining the card picked by the player
			//By printing the card depending on their choice of 1-5
			//Calling the cardFace and cardSuit arrays
			if (cardPicked == 1)
			{
				cardPicked = player[i].cardPicked[i];
				printf("\nYou Chose the card %s of %s\n", player[i].cardFace[0], player[i].cardSuit[0]);
			}
			else if (cardPicked == 2)
			{
				cardPicked = player[i].cardPicked[i];
				printf("\nYou Chose the card %s of %s\n", player[i].cardFace[1], player[i].cardSuit[1]);
			}
			else if (cardPicked == 3)
			{
				cardPicked = player[i].cardPicked[i];
				printf("\nYou Chose the card %s of %s\n", player[i].cardFace[2], player[i].cardSuit[2]);
			}
			else if (cardPicked == 4)
			{
				cardPicked = player[i].cardPicked[i];
				printf("\nYou Chose the card %s of %s\n", player[i].cardFace[3], player[i].cardSuit[3]);
			}
			else if (cardPicked == 5)
			{
				cardPicked = player[i].cardPicked[i];
				printf("\nYou Chose the card %s of %s\n", player[i].cardFace[4], player[i].cardSuit[4]);
			}


		}


		printf("\n\n");

		int proceed = 1;

		printf("\n\nProceed to Next Round? - 1)Yes :");
		scanf("%d", &proceed);


		//IF/ELSE TO ASSIGN EACH CARD INC. SUITS A cardValue if TRUMP SUIT
		//================================================================

		//CLUBS
		if (trumpCard == suit[0])
		{
			if (face[0] && suit[0])
			{
				cardValue = 0;
			}
			else if (face[1] && suit[0])
			{
				cardValue = 1;
			}
			else if (face[2] && suit[0])
			{
				cardValue = 2;
			}
			else if (face[3] && suit[0])
			{
				cardValue = 13;
			}
			else if (face[4] && suit[0])
			{
				cardValue = 4;
			}
			else if (face[5] && suit[0])
			{
				cardValue = 5;
			}
			else if (face[6] && suit[0])
			{
				cardValue = 6;
			}
			else if (face[7] && suit[0])
			{
				cardValue = 7;
			}
			else if (face[8] && suit[0])
			{
				cardValue = 8;
			}
			else if (face[9] && suit[0])
			{
				cardValue = 11;
			}
			else if (face[10] && suit[0])
			{
				cardValue = 9;
			}
			else if (face[11] && suit[0])
			{
				cardValue = 10;
			}
			else if (face[12] && suit[0])
			{
				cardValue = 12;
			}
		}

		//DIAMONDS
		if (trumpCard == suit[1])
		{
			if (face[0] && suit[1])
			{
				cardValue = 0;
			}
			else if (face[1] && suit[1])
			{
				cardValue = 1;
			}
			else if (face[2] && suit[1])
			{
				cardValue = 2;
			}
			else if (face[3] && suit[1])
			{
				cardValue = 13;
			}
			else if (face[4] && suit[1])
			{
				cardValue = 4;
			}
			else if (face[5] && suit[1])
			{
				cardValue = 5;
			}
			else if (face[6] && suit[1])
			{
				cardValue = 6;
			}
			else if (face[7] && suit[1])
			{
				cardValue = 7;
			}
			else if (face[8] && suit[1])
			{
				cardValue = 8;
			}
			else if (face[9] && suit[1])
			{
				cardValue = 11;
			}
			else if (face[10] && suit[1])
			{
				cardValue = 9;
			}
			else if (face[11] && suit[1])
			{
				cardValue = 10;
			}
			else if (face[12] && suit[1])
			{
				cardValue = 12;
			}
		}

		//HEARTS
		if (trumpCard == suit[2])
		{
			if (face[0] && suit[2])
			{
				cardValue = 0;
			}
			else if (face[1] && suit[2])
			{
				cardValue = 1;
			}
			else if (face[2] && suit[2])
			{
				cardValue = 2;
			}
			else if (face[3] && suit[2])
			{
				cardValue = 13;
			}
			else if (face[4] && suit[2])
			{
				cardValue = 4;
			}
			else if (face[5] && suit[2])
			{
				cardValue = 5;
			}
			else if (face[6] && suit[2])
			{
				cardValue = 6;
			}
			else if (face[7] && suit[2])
			{
				cardValue = 7;
			}
			else if (face[8] && suit[2])
			{
				cardValue = 8;
			}
			else if (face[9] && suit[2])
			{
				cardValue = 11;
			}
			else if (face[10] && suit[2])
			{
				cardValue = 9;
			}
			else if (face[11] && suit[2])
			{
				cardValue = 10;
			}
			else if (face[12] && suit[2])
			{
				cardValue = 12;
			}
		}

		//SPADES
		if (trumpCard == suit[3])
		{
			if (face[0] && suit[3])
			{
				cardValue = 0;
			}
			else if (face[1] && suit[3])
			{
				cardValue = 1;
			}
			else if (face[2] && suit[3])
			{
				cardValue = 2;
			}
			else if (face[3] && suit[3])
			{
				cardValue = 13;
			}
			else if (face[4] && suit[3])
			{
				cardValue = 4;
			}
			else if (face[5] && suit[3])
			{
				cardValue = 5;
			}
			else if (face[6] && suit[3])
			{
				cardValue = 6;
			}
			else if (face[7] && suit[3])
			{
				cardValue = 7;
			}
			else if (face[8] && suit[3])
			{
				cardValue = 8;
			}
			else if (face[9] && suit[3])
			{
				cardValue = 11;
			}
			else if (face[10] && suit[3])
			{
				cardValue = 9;
			}
			else if (face[11] && suit[3])
			{
				cardValue = 10;
			}
			else if (face[12] && suit[3])
			{
				cardValue = 12;
			}
		}


		//ADDING PLAYER SCORE

		if (cardValue > cardValue)
		{
			player[i].playerScore += 5;
		}

		//clear screen
		system("@cls||clear");

		roundPoints();

		playerCount = 0;

		for (int i = 0; i < numOfPlayers; i++)
		{
			playerCount++;
			printf("\nPlayer %d Score : %d", playerCount, playerScore);
		}

	}

	fclose(gameHistory);

}

void gameRules()
{
	//TRUMP CARD RULE
	if (suit[i] == suit[2])
	{
		face[4] > face[9] > face[12] > face[11] > face[10] > face[8] > face[7] > face[6] > face[5] > face[3] > face[2] > face[1] >face[0];
	}
	else if(suit[i] == suit[3])
	{
		face[4] > face[9] > face[12] > face[11] > face[10] > face[8] > face[7] > face[6] > face[5] > face[3] > face[2] > face[1] > face[0];
	}
	else if (suit[i] == suit[1])
	{
		face[4] > face[9] > face[12] > face[11] > face[10] > face[8] > face[7] > face[6] > face[5] > face[3] > face[2] > face[1] > face[0];
	}
	else if (suit[i] == suit[0])
	{
		face[4] > face[9] > face[12] > face[11] > face[10] > face[8] > face[7] > face[6] > face[5] > face[3] > face[2] > face[1] > face[0];
	}
}


void roundPoints()
{
	//clear screen
	system("@cls||clear");

	printf("===============================\n");
	printf("	  Scoreboard          |\n");
	printf("===============================\n");

}

void createDeck()
{
	//Hardcoding the deck contents
	//DECK ARRAY
	strcpy(face[0], "2" , 0);
	strcpy(face[1], "3" , 1);
	strcpy(face[2], "4" , 2);
	strcpy(face[3], "5" , 12);
	strcpy(face[4], "6" , 4);
	strcpy(face[5], "7" , 3);
	strcpy(face[6], "8" , 5);
	strcpy(face[7], "9" , 6);
	strcpy(face[8], "10" , 7);
	strcpy(face[9], "J" , 11);
	strcpy(face[10], "Q" , 8);
	strcpy(face[11], "K" , 9);
	strcpy(face[12], "A" , 10);

	//SUIT ARRAY
	strcpy(suit[0], "Clubs" , 0);
	strcpy(suit[1], "Diamonds" , 1);
	strcpy(suit[2], "Hearts" , 2);
	strcpy(suit[3], "Spades" , 3);

}