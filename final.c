#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetboard();
void printboard();
int checkfreespace();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);

int main()
{
    char winner = ' ';
    resetboard();
    while(winner==' '&&checkfreespace()!=0)
    {
        printboard();
        playermove();
        winner=checkwinner();
        if(winner!=' '||checkfreespace()==0)
        {
            break;
        }
        computermove();
        winner=checkwinner();
        if(winner!=' '||checkfreespace()==0)
        {
            break;
        }
        
    }
        printboard();
        printwinner(winner);
    return 0;
}

void resetboard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printboard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkfreespace()
{
    int freespace=9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                freespace--;
            }
        }
    }
    return freespace;
}
void playermove(){

    int x,y;
    do
    {
        printf("enter row number(1-3): \n");
    scanf("%d",&x);
    printf("enter column number(1-3): \n");
    scanf("%d",&y);
    if(board[x][y]!=' '){
        printf("INVALID MOVE!!");
    }
    else{
        board[x][y]=PLAYER;
        break;
    }
    } while (board[x][y]!=' ');
    

}
void computermove()
{
    int x,y;
    srand(time(0));
    if (checkfreespace()>0)
    {
        do
        {
            x=rand()%3;
            y=rand()%3;
    
        } while (board[x][y]!=' ');
        board[x][y]=COMPUTER;
    }
    else{
        printwinner(' ');
    }
    
}
char checkwinner()
{   //check column;
    for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
            {
                return board[i][0];
            }
        
    }
    //check row
     for(int i=0;i<3;i++){
            if(board[0][i]==board[1][i]&&board[0][i]==board[2][i])
            {
                return board[0][i];

            }
        
    }
    //check diagonal
    if(board[0][2]==board[1][1]&&board[0][1]==board[2][2])
    {
        return board[0][2];
    }
    if(board[0][2]==board[1][1]&&board[0][2]==board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}
void printwinner(char winner)
{
    if(winner==PLAYER)
    {
        printf("you win!!");
    }
    else if(winner==COMPUTER)
    {
        printf("you lose!!");
    }
    else{
        printf("MATCH DRAW!!");
    }
}