#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_CHARNAME    15 
#define N_PLAYER        3
#define MAX_DIE         6

#define PLAYERSYATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2


//�ʿ��� �������� ����
         //���� define���� player ���� �����ϸ� �迭�� ũ�Ⱑ �ٲ�� 
int player_position[N_PLAYER]; 

    //2���� �迭�� ����� ���� �̸��� ���� 
char player_name[N_PLAYER][MAX_CHARNAME];

int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0-live, 1-die, 2-end

    //live, die, end�� ���ڿ��� �����ϴ� �迭 
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};


//game start
void opening(void) {
     printf("|=*==**===***========***===**==*=|\n");
     printf("            shark game             \n");
     printf("|=*==**===***========***===**==*=|\n\n");
     printf("starts now!\n");
}

//rolling the dice 1~6
int rolldie (void)
{
    return rand() % MAX_DIE + 1;

}

void printPlayerPosition(int player)
{
     int i;
     
     //print Player's first letter to show where he is
     for (i=0;i<N_BOARD;i++)
     {
      printf("|");
     }
     if (i == player_position[player])
        printf("%c", player_name[player]);
     else
     {
         if(board_getBoardStatus(i) = BOARDSTATUS_NOK) // board.c�� ������ ����Ǿ� ���� => �Լ� ȣ�� 
         printf("X");
         else
         printf(" ");
     }
     
     printf("|\n");
     
     }
     
//show player's status
void printPlayerStatus(void)
{
     int i;
     printf("player status ---\n");
     
     // p name : position, coin, status / one by one, so use 'for'
     for (i = 0; i < N_PLAYER; i++)
     {
         printf("%s : position %i, coin %i. status %s\n", player_name[i], player_position[i], player_statusStirng[player_status[i]);
         printPlayerPosition(i);
     }
     pritnf("-------------------\n"):
}

void checkDie(void)
{
     int i;
     for (i = 0; i < N_PLAYER; i++)
         if(board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
             player_status[i] = PLAYERSTATUS_DIE;
}

int main(int argc, char *argv[])
{
    int i = 0; // for 'for'
    int pos = 0;
    int turn = 0; // to get player's turn
    
    srand((unsigned)time(NULL));
    
    //0.opening
    opening();
    
    //1. variable initialize & input player's name
    board_initBoard();
    
    //1-2. use 'for' to make player's fresh
    for (i = 0;i < N_PLAYER; i++)//use macro
    {
        player_position[i] = 0;
        playter_coin[i] = 0;
        player_status[i] = PLAYER_STATUS_LIVE;
        
        //player name input
        printf("PLAYER %i's name: ", i);
        scanf("%s", player_name[i]); //do not use &. it's already a pointer
        
    }
    
    //2. repeat (player's turn)
    do 
    {
        int step = rolldie();
        int coinResult;
        char c;
        
        //���� �ڵ带 �����ϸ� �ȵǴ� ��� (�÷��̾��� ����) 
        if (player_status[turn]!= PLAUERSTATUS_LIVE)
        {
             turn = (turn + 1) % N_LAYER;
             continue:
         }
        
        pos += step;
        
         //2-1. print player's statement
         board_printBoardStatus();//board.c�� ���� 
        
         
         for (i=0;i<N_PLAYER;i++)
         {
             printPlayerPosition(i);
             printPlayerStatus();
         }
         
         //2-2. roll the dice
         printf("%s's turn!!\n", player_name[turn]);
         printf("press enter to roll the dice\n");
         scanf("%d", &c); // ������ ����� �� ������ while���� �ʹ� ���� ���Ƽ� ������ ���� �����ϴ� ������ ����� ����
         fflush(stdin); //ǥ�� �Է� flush 
         
         step = rolldie();               
         
         //2-3. move
         player_name[turn] += step;
         
         // ������ ���� ������ �̵��� ���  
         if (player_position[turn] >= N_BOARD)
            player_position[trun] = N_BOARD - 1;
         if (player_position[turn] == N_BOARD - 1)
            player_status[turn] = PLAYERSTATUS_END;
            //printf() �� �������� ��ŭ ���������� �˷��ֱ�
         printf("%s reached the end!\n", player_name[turn]);
             
         //2-4. earn coin
         coinResult = board_getboardVoin(pos);
         palyer coin[turn]+= coinResult; //���� �ջ�  
         
         //printf()�� ��ŭ ������ ������� �˷��ֱ�
         printf("%s earned %d coins!\n", player_name[turn], coinResult);
         
         //2-5. next turn
         turn = (turn + 1) % N_PLAYER; // 0 1 2 --- N_PLAYER ������ ���� ���ƾ��� ���� �׳� turn = turm + 1; �� �ƴ϶� ������ ������ ���
          
         //2-6. if( all player's should have taken his turn )
                //shark chase on
         if (turn == 0)
         {
                  //��� ����
                  int shark_pos = board_stepShark();
                  //printf();�� ���� �˸���  
                  checkDie(); 
         }
    } while(1);        
     // �÷��̾��� ���°� DIE���� Ȯ�� �� 2�� �̻� ��������� ������ ����. 1�� ���� ��� �� 1 ���� winner�� �ǰ� ��ΰ� ������� printf�� ��ΰ� ������ �˸���  
    //3. game ends ( winner, print )
         
  system("PAUSE");	
  return 0;
}
