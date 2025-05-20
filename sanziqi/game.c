#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

void menu(void)
{
	printf("*********************************\n");
	printf("********1. play  0. exit*********\n");
	printf("*********************************\n");
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for(i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割信息
		if (i < row - 1)
		{
			int m = 0;
			for (m = 0; m < col; m++)
			{
				printf("---");
				if(m < col -1)
			         printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家请下棋\n");
	printf("请输入坐标！\n");
	while (1)
	{
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//坐标合法
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else 
			{
				printf("坐标被占用！\n");
			}
		}
		else
		{
			printf("坐标输入有误！\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	int m = 0;
	do
	  {
		 x = rand() % row;//0~row	
		 y = rand() % col;
		 m = rand() % 8;
		 if (board[x][y] == '*')
		 {
		 	switch (m)
		 	{
			case 0:
				if (x - 1 >= 0 && y - 1 >= 0)
				{
					if (board[x - 1][y - 1] == ' ')
					{
						board[x - 1][y - 1] = '#';
						m = 8;
					}
				}
				break;

			case 1:
				if (x - 1 >= 0 && y >= 0)
				{
					if (board[x - 1][y] == ' ')
					{
						board[x - 1][y] = '#';
						m = 8;
					}
				}
				break;

			case 2:
				if (x - 1 >= 0 && y + 1 >= 0)
				{
					if (board[x - 1][y + 1] == ' ')
					{
						board[x - 1][y + 1] = '#';
						m = 8;
					}
				}
				break;

			case 4:
				if (x + 1 >= 0 && y >= 0)
				{
					if (board[x + 1][y] == ' ')
					{
						board[x + 1][y] = '#';
						m = 8;
					}
				}
				break;

			case 5:
				if (x >= 0 && y + 1 >= 0)
				{
					if (board[x][y + 1] == ' ')
					{
						board[x][y + 1] = '#';
						m = 8;
					}
				}
				break;

			case 6:
				if (x + 1 >= 0 && y - 1 >= 0)
				{
					if (board[x + 1][y - 1] == ' ')
					{
						board[x + 1][y - 1] = '#';
						m = 8;
					}
				}
				break;

			case 7:
				if (x + 1 >= 0 && y + 1 >= 0)
				{
					if (board[x + 1][y + 1] == ' ')
					{
						board[x + 1][y + 1] = '#';
						m = 8;
					}
				}
				break;
			}
		 }
	  } while(m<8);
}

void game()
{
	char board[ROW][COL] = { 0 };
	//初始化棋盘的功能
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
	}

}