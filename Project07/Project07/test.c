#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("-----------------------------------\n");
	printf("------------1.��������Ϸ-----------\n");
	printf("------------0.�˳���Ϸ-------------\n");
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
		printf("��Ӯ�ˣ�\n");
	else if (ret == '#')
	{
		printf("�����ˣ�\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}

}
	
int main()
{
	srand((unsigned int)time(NULL));

	int input = 0;

	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;

		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}