#include <stdio.h>
#include <stdlib.h>
#include "board.h"
 
#define N_BOARD   15
#define N_COINPOS 12
#define MAX_COIN  4

static int board_status[N_BOARD]; // �ļ� �ƴ��� �ƴ��� ����  
static int board_coin[N_BOARD]; //��� ĭ�� ���� ������ ������ �ִ°� 

//��� ��ġ  
static int board_sharkPosition;

//���� �ʱ�ȭ 
int board_initBoard(void)
{
    int i;
    for(i=0;i<N_BOARD;i++)
    {       
            //board_status�� i��° ��� OK���� ����
            board_status[i] = BOARDSTATUS_OK; 
            //board_coin�� i��° ��� 0����;
            board_coin[i] = 0;
    }
    //coin �Ҵ� 
    for(i=0;i<N_COINPOS;i++)
    {
            //while���� ������ ���� ����  
            int flag = 0;
            
            while (flag == 0)//i��° coin�� �Ҵ���� ������ �ݺ�
            {
                  //������ ���� ĭ�� �������� ���� 
                  int allocpos = rand()%N_BOARD;
                  if (board_coin[allocpos] == 0)//ĭ�� ������ �̹� ���� ������
                  {
                             //i��° coin �Ҵ�
                             //board_coin[����ĭ] = (1~MAX_COIN �� ����)
                             board_coin[allocpos] = rand()%MAX_COIN+1; 
                             
                             //while�� Ż��
                             flag = 1; 
                  }
            }
    }
} 

//��ü ���� ���� ���
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

//Ư�� ĭ�� �ļ� ���� ��� 
void board_getBoardStatus (int pos)
{
     return board_status[pos];
}

//���� ���� ���  
int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    // ���� ���� ���� �ۼ� �� 0�� ���
    
    return coin;
} 


//��� ��ġ ���  
int board_getSharkPosition(void);

//��� ���� ���  
int board_stepShark(void);


