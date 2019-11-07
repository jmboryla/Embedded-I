#include <stdio.h>            // printf, scanf, puts
#include <stdlib.h>           // exit

/** game play macro definitions */
#define XPLAYER  0
#define OPLAYER  1
#define OPEN     2
#define LIVEGAME 3
#define TIEGAME  4

/** menu choice macro definitions */
#define QUITGAME 2

const char display[3]={'X','O',' '};
/*** function prototypes ***/

//void startScreen(void);



/* Purpose: display start screen information
   input: none
   returns nothing
*/
void startScreen(void)
{
   char input;
   printf("Tic Tac Toe\n\n");
   printf("enter any key to continue ...");
   scanf("%c", &input);
}

/* Purpose:
      - display menu showing user choices
      - read user choice from standard input stream

   input: none
   returns user choice

   note: does not validate user choice
*/
int getUserGameChoice(void)
{
   int choice;
   puts("\n\nMain Menu\n");
   puts("1. start new game");
   puts("2. quit");
   printf("enter choice: ");
   scanf("%d", &choice);
   return choice;

}

/* Purpose: display tic tac toe board that shows
            each square's numeric value

   input:  none
   returns nothing
*/
void displayStaticGameBoard(void)
{
   printf("\n\n");
   printf("%5s|%5s|%5s\n", "","", "" );
   printf("  %c  |  %c  |  %c\n", '1', '2','3');
   printf("_____|_____|_____\n");
   printf("%5s|%5s|%5s\n", "","", "" );
   printf("  %c  |  %c  |  %c\n", '4', '5', '6');
   printf("_____|_____|_____\n");
   printf("%5s|%5s|%5s\n", "","", "" );
   printf("  %c  |  %c  |  %c\n", '7', '8', '9');
   puts("\n\n\n");

}


/* Purpose: display game board, showing X's and O's

   input:  gameboard, gameboard size

   returns nothing
*/
void displayLiveGameBoard(int gameBoard[],display[])
{
   printf("\n\n");
   printf("%5s|%5s|%5s\n", "","", "" );
   printf("  %c  |  %c  |  %c\n", display[gameboard[0]],display[gameboard[1]],display[gameboard[2]]);
   printf("_____|_____|_____\n");
   printf("%5s|%5s|%5s\n", "","", "" );
   printf("  %c  |  %c  |  %c\n", display[gameboard[3]],display[gameboard[4]],display[gameboard[5]]);
   printf("_____|_____|_____\n");
   printf("%5s|%5s|%5s\n", "","", "" );
   printf("  %c  |  %c  |  %c\n", display[gameboard[6]],display[gameboard[7]],display[gameboard[8]]);
   puts("\n\n\n");

}




/* Purpose:

   input:
      whichPlayer - indicates current player

   returns gameboard square location

   note: return value has not been validated
*/
int selectSquare(int whichPlayer){
   int move;
   printf("Player %d, enter move: ", whichPlayer);
   scanf("%d", &move);
   return move;
}


/* Purpose: initialize each game board square as OPEN

   input: gameboard, game board size

   returns nothing
*/
void initializeGameBoard(int gameboard[], int arraySize)
{
   int i;
   for(i = 0; i < arraySize; ++i)
      gameboard[i] = OPEN;
}


/* Purpose: determines whether game is over and the winner, if any

   input: game board, game board size

   returns XPLAYER when X wins the game
           OPLAYER when O wins the game
           TIEGAME when there is a tie game
           LIVEGAME when there is no winner
*/
int checkWinner(){
   puts("checkWinner() function is a work in progress");
   return LIVEGAME;
}

/** Purpose: Implements player taking turn to place
             an X or an O on the game board

    Actions:
            - display the static game board
            - player marks valid game board location
            - display updated game board
*/
void playerTakesTurn(int gameBoard[],int currentPlayer)
{
    int squareNumber;
    int validMove=0;

    while (!validMove)
    {


       // display the static game board
       displayStaticGameBoard();

       // player marks valid square
        squareNumber=selectSquare(currentPlayer);
        while(squareNumber<1 || squareNumber>9)
        {
            puts("out of range, try again");
            squareNumber=selectSquare(currentPlayer);
        }
        if(gameBoard[squareNumber-1]!=OPEN)
        else
        {
            gameboard[squareNumber-1]=currentPlayer
            validMove=1
        }
       // display updated game board
        displayLiveGameBoard(tttBoard,display);
    }
}


int main()
{
   // user input variables
   int menuChoice;

   // game play variables
   int tttBoard[9];
   int currentPlayer;


   /** Start up routine
         - display start screen
         - user chooses to play game or quit program

   startScreen();
   menuChoice = getUserGameChoice();
   if(menuChoice == QUITGAME){
      puts("\n\nQuitting program, thanks for playing\n");
      exit(EXIT_SUCCESS);
   }

   */

    /*** start new game ***/
    // set all game board locations as open
    initializeGameBoard(tttBoard,9);
    currentPlayer=XPLAYER;
    // keep playing game until there is a winner or a tie
    do{

         // player takes turn
         playerTakesTurn(tttBoard,currentPlayer);

    }while(checkWinner() == LIVEGAME);

    /** Game over **/

    // Display winner or time game message

    // Program ends
    return 0;
}
