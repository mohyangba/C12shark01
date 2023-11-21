#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"\

#define MAX_DIE    6

void opening (void) {
     printf("|=*==**===***========***===**==*=|\n");
     printf("            shark game             \n");
     printf("|=*==**===***========***===**==*=|\n\n");
     printf("starts now!\n");
}

int rolldie (void)
{
    rreturn rand()%MAX_DIE+1;

}

int main(int argc, char *argv[])
{
    int pos = 0;
    srand((unsigned)time(NULL));
    
    //0.opening
    opening();
    
    //1. variable initialize & input player's name
    board_initboard();
    
    //2. repeat (player's turn)
    do {
        int step =rolldie();
        int coinResult;
        char c;
        
        pos += step;
        printf("여기저리로 이렇게저렇게 이동했습니다");
        coinResult = board_getBoardCoin();
        
        scanf("%d", &c); 
        fflush(stdin);
         //2-1. print player's statement
         //2-2. roll the dice
         //2-3. move
         //2-4. earn coin
         //2-5. next turn
         //2-6. if( all player's should have taken his turn )
                //shark chase on
                } while(1);         
    //3. game ends ( winner, print )
         
    
  
  system("PAUSE");	
  return 0;
}
