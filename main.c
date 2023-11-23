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


//필요한 전역변수 설정
         //위의 define에서 player 수만 변경하면 배열의 크기가 바뀌도록 
int player_position[N_PLAYER]; 

    //2차원 배열을 사용해 유저 이름을 저장 
char player_name[N_PLAYER][MAX_CHARNAME];

int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0-live, 1-die, 2-end

    //live, die, end를 문자열로 저장하는 배열 
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
         if(board_getBoardStatus(i) = BOARDSTATUS_NOK) // board.c에 정보가 저장되어 있음 => 함수 호출 
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
        
        //밑의 코드를 실행하면 안되는 경우 (플레이어의 죽음) 
        if (player_status[turn]!= PLAUERSTATUS_LIVE)
        {
             turn = (turn + 1) % N_LAYER;
             continue:
         }
        
        pos += step;
        
         //2-1. print player's statement
         board_printBoardStatus();//board.c에 있음 
        
         
         for (i=0;i<N_PLAYER;i++)
         {
             printPlayerPosition(i);
             printPlayerStatus();
         }
         
         //2-2. roll the dice
         printf("%s's turn!!\n", player_name[turn]);
         printf("press enter to roll the dice\n");
         scanf("%d", &c); // 실제로 사용은 안 하지만 while문이 너무 빨리 돌아서 유저가 직접 개입하는 순간을 만들기 위함
         fflush(stdin); //표준 입력 flush 
         
         step = rolldie();               
         
         //2-3. move
         player_name[turn] += step;
         
         // 유저가 보드 끝까지 이동한 경우  
         if (player_position[turn] >= N_BOARD)
            player_position[trun] = N_BOARD - 1;
         if (player_position[turn] == N_BOARD - 1)
            player_status[turn] = PLAYERSTATUS_END;
            //printf() 로 유저에게 얼만큼 움직였는지 알려주기
         printf("%s reached the end!\n", player_name[turn]);
             
         //2-4. earn coin
         coinResult = board_getboardVoin(pos);
         palyer coin[turn]+= coinResult; //코인 합산  
         
         //printf()로 얼만큼 코인을 얻었는지 알려주기
         printf("%s earned %d coins!\n", player_name[turn], coinResult);
         
         //2-5. next turn
         turn = (turn + 1) % N_PLAYER; // 0 1 2 --- N_PLAYER 까지만 수가 돌아야함 따라서 그냥 turn = turm + 1; 이 아니라 나머지 연산을 사용
          
         //2-6. if( all player's should have taken his turn )
                //shark chase on
         if (turn == 0)
         {
                  //상어 동작
                  int shark_pos = board_stepShark();
                  //printf();로 상태 알리기  
                  checkDie(); 
         }
    } while(1);        
     // 플레이어의 상태가 DIE인지 확인 후 2명 이상 살아있으면 게임을 지속. 1명만 남은 경우 그 1 명이 winner가 되고 모두가 죽은경우 printf로 모두가 죽음을 알리기  
    //3. game ends ( winner, print )
         
  system("PAUSE");	
  return 0;
}
