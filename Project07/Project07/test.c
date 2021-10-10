#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("-----------------------------------\n");
	printf("------------1.三子棋游戏-----------\n");
	printf("------------0.退出游戏-------------\n");
	printf("-----------------------------------\n");
}

void game()
{
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);

	DisplayBoard(board, ROW, COL);

	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
		printf("您赢了！\n");
	else if (ret == '#')
	{
		printf("您输了！\n");
	}
	else
	{
		printf("平局！\n");
	}

}
	
int main()
{
	srand((unsigned int)time(NULL));

	int input = 0;

	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！");
			break;

		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);

	return 0;
}