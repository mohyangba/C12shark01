//main.c�� �˷����ϴ� �����̹Ƿ� board.h�� �̵� 
#define BOARDSTATUS_OK  1
#define BOARDSTATUS_NOK 0
#define N_BOARD   15

//���� �ʱ�ȭ 
int board_initialize(void);

//��ü ���� ���� ���
int board_printstatus(void);

//���� ���� ���
int board_getcoin(int pos);

//��� ��ġ ���
int board_sharkposition(void);

//��� ���� ���
int board_moveshark(void);

//Ư�� ĭ�� �ļ� ���� ��� 
void board_getBoardStatus (int pos);
