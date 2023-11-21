#include <stdio.h>
#include <stdlib.h>
#include "board.h"
 
#define N_BOARD   15
#define N_COINPOS 12
#define MAX_COIN  4

static int board_status[N_BOARD]; // 파손 됐는지 아닌지 저장  
static int board_coin[N_BOARD]; //어느 칸이 얼마의 코인을 가지고 있는가 

//상어 위치  
static int board_sharkPosition;

//보드 초기화 
int board_initBoard(void)
{
    int i;
    for(i=0;i<N_BOARD;i++)
    {       
            //board_status의 i번째 요소 OK상태 설정
            board_status[i] = BOARDSTATUS_OK; 
            //board_coin의 i번째 요소 0설정;
            board_coin[i] = 0;
    }
    //coin 할당 
    for(i=0;i<N_COINPOS;i++)
    {
            //while문을 조종할 변수 설정  
            int flag = 0;
            
            while (flag == 0)//i번째 coin이 할당되지 않으면 반복
            {
                  //동전을 놓을 칸을 랜덤으로 지정 
                  int allocpos = rand()%N_BOARD;
                  if (board_coin[allocpos] == 0)//칸에 동전이 이미 있지 않으면
                  {
                             //i번째 coin 할당
                             //board_coin[지정칸] = (1~MAX_COIN 중 랜덤)
                             board_coin[allocpos] = rand()%MAX_COIN+1; 
                             
                             //while문 탈출
                             flag = 1; 
                  }
            }
    }
} 

//전체 보드 상태 출력
int board_printBoardStatus(void)
{
    int i;
    pirntf("------------BOARD STATUS------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
           printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("-------------------------------------\n");
    
    return 0; //detail
}

//특정 칸의 파손 여부 출력 
void board_getBoardStatus (int pos)
{
     return board_status[pos];
}

//동전 습득 명령  
int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    // 지역 변수 없이 작성 시 0만 출력
    
    return coin;
} 


//상어 위치 출력  
int board_getSharkPosition(void);

//상어 전진 명령  
int board_stepShark(void);


