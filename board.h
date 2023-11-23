//main.c에 알려야하는 내용이므로 board.h로 이동 
#define BOARDSTATUS_OK  1
#define BOARDSTATUS_NOK 0
#define N_BOARD   15

//보드 초기화 
int board_initialize(void);

//전체 보드 상태 출력
int board_printstatus(void);

//동전 습득 명령
int board_getcoin(int pos);

//상어 위치 출력
int board_sharkposition(void);

//상어 전진 명령
int board_moveshark(void);

//특정 칸의 파손 여부 출력 
void board_getBoardStatus (int pos);
