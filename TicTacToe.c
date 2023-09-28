#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void playWithFriend();
int isValidPosition(char);
void update(char, int);
int checkWin();
void reset();
 //playWithSmartComputer();
 //playWithEvilComputer();

char board[3][3]={'1','2','3','4','5','6','7','8','9'};
int main()
{
    system("cls");
    //char player1[15], player2[15];
    char choice;

    again : 
    printf("\t\tWelcome to Tic-Tac-Toe\n");
    printf("Enter your choice : \n");
    printf("1. Want to Play with your friend.\n");
    //printf("2. Want to Play with Smart Computer.\n");
    //printf("3. Want to Play with Evil Computer.\n");
    printf("4. Exit.\n");

    choice = getch();
    switch(choice)
    {
        case '1' : system("cls");
        playWithFriend();
        break;

        case '2' : //system("cls");
        printf("This is not completed yet, This feature will come in 2-3 days.");
        //playWithSmartComputer();
        break;

        case '3' : //system("cls");
        printf("This is not completed yet, This feature will come in 2-3 days.");
        //playWithEvilComputer();

        break;
        case '4' : system("cls");
        printf("Your choice is to exit from the game.\t ThankYou for playing Game...\n");
        printf("Press any key to exit from the game...");
        getch();
        break;

        default :
        system("cls");
         printf("You Entered wrong choice. Please Enter again : \n");
        goto again;
    }
    
    return 0;
}

void playWithFriend()
{
    int turn=1;

    start:
    system("cls");
    printf("\t\t\t Tic-Tac-Toe\n");
    printf("#############################################################\n");

    printf("\n\tPlayer1 -> X, Player2 -> O\n\n");

    printf("#############################################################\n");
    
    printf("___________________\n");
    printf("|     |     |     |\n");
    for(int i=0;i<3;i++)
    {
        printf("|");
        for(int j=0;j<3;j++)
        {
            printf("  %c  |", board[i][j]);
        }
        printf("\n|     |     |     |\n");
    }
    printf("|_____|_____|_____|\n");
    printf("\n#############################################################\n");

    if(checkWin() == 1) // Player1 Wins the game
    {

        printf("***********************************************\n");
        printf("*                                             *\n");
        printf("*          Player1 Wins the game...           *\n");
        printf("*                                             *\n");
        printf("***********************************************\n\n");

        printf("If, You want to play the game again... Press 1 otherwise Press any key");
        if(getch() == '1')
        {
            turn = 1;
            reset();
            goto start;
        }
        else
         exit(0);
    }
    
    else if(checkWin() == 2) // Player2 Wins the game
    {
        printf("***********************************************\n");
        printf("*                                             *\n");
        printf("*          Player2 Wins the game...           *\n");
        printf("*                                             *\n");
        printf("***********************************************\n\n");

        printf("If, You want to play the game again... Press 1 otherwise Press any key");
        if(getch() == '1')
        {
            turn = 1;
            reset();
            goto start;
        }
        else
         exit(0);
    }




    while(turn != 10)
    {
        char pos;
        if(turn % 2 == 0)
        {
            printf("\n");
            pos1:
            printf("\nEnter the position for Player2 : ");
            scanf("%c",&pos);
            // For exit the game
            if(pos == 'e' || pos == 'E')
             exit(0);

            fflush(stdin);
            if(isValidPosition(pos))
            {
                turn++;
                update(pos, 1);
                goto start;
            }
            else
            {
                printf("You Entered wrong choice...");
             goto pos1;
            }
        }
        else
        {
            printf("\n");
            pos2 :
            printf("Enter the position for Player1 : ");
            scanf("%c",&pos);
            // For exit the game
            if(pos == 'e' || pos == 'E')
             exit(0);

            fflush(stdin);
            if(isValidPosition(pos))
            {
                turn++;
                update(pos, 2);
                goto start;
            }
            else
            {
                printf("You Entered wrong choice...");
               goto pos2;
            }
        }
    }

    printf("\n**********Draw Game!!!***********\n");
    printf("If, You want to play the game again... Press 1 otherwise Press any key");
    if(getch() == '1')
    {
        turn = 1;
        reset();
        goto start;
    }
    else
        exit(0);

}

void update(char pos, int player)
{
    char c = 'O';
    if(player == 2)
     c='X';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == pos)
             board[i][j] = c;
        }
    }
}

int isValidPosition(char pos)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == pos)
             return 1;
        }
    }
    return 0;
}

int checkWin()
{
    int count=0;
    // Check for Player1 -> 'O'
    
    // Check row 1
    for(int i=0;i<3;i++)
            if(board[0][i] == 'X')
             count++;
    
    if(count == 3)
        return 1;
    count=0;
    
    // Check row 2
    for(int i=0;i<3;i++)
            if(board[1][i] == 'X')
             count++;
    
    if(count == 3)
        return 1;
    count = 0;

    // Check row 3

    for(int i=0;i<3;i++)
            if(board[2][i] == 'X')
             count++;
    
    if(count == 3)
        return 1;
    count = 0;

    // Check column 1

    for(int i=0;i<3;i++)
            if(board[i][0] == 'X')
             count++;
    
    if(count == 3)
        return 1;
    count = 0;

    // Check column 2
    for(int i=0;i<3;i++)
        if(board[i][1] == 'X')
             count++;
    
    if(count == 3)
        return 1;
    count = 0;

    // Check Diagonal 1 
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        return 1;

    // Check Diagonal 2 
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        return 1; 


    //*****Check for Player2 -> 'O'*****************************************************

    // Check row 1
    for(int i=0;i<3;i++)
            if(board[0][i] == 'O')
             count++;
    
    if(count == 3)
        return 2;
    count=0;
    
    // Check row 2
    for(int i=0;i<3;i++)
            if(board[1][i] == 'O')
             count++;
    
    if(count == 3)
        return 2;
    count = 0;

    // Check row 3

    for(int i=0;i<3;i++)
            if(board[2][i] == 'O')
             count++;
    
    if(count == 3)
        return 2;
    count = 0;

    // Check column 1

    for(int i=0;i<3;i++)
            if(board[i][0] == 'O')
             count++;
    
    if(count == 3)
        return 2;
    count = 0;

    // Check column 2
    for(int i=0;i<3;i++)
            if(board[i][1] == 'O')
             count++;
    
    if(count == 3)
        return 2;
    count = 0;

    // Check column 3
    for(int i=0;i<3;i++)
            if(board[i][2] == 'O')
             count++;
    
    if(count == 3)
        return 2;
    count = 0;

    // Check Diagonal 1
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        return 2;

    // Check Diagonal 2 
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        return 2;

    return 0;

}

void reset()
{
    char k='1';
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = k++;
}