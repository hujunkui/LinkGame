#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#define ROWS 15
#define COLS 12
int arr[ROWS][COLS];//储存地图
int arr1[2][25], arr2[2][25];//储存空位置坐标
int i, j, k, l;//循环变量
int x1, y1, x2, y2;//储存选中的坐标
int x3, x4, y3, y4;
int flag, x;//判断标志
MOUSEMSG m;
IMAGE image0,image1, image2, image3, image4, image5,image6, image7,image8,image9,image10;
void UI();//初始化用户界面
void printimage();
void contralGame();
void judge();
void storeLocation(int x1, int y1, int x2, int y2);
void judge2();
void judge3(int x3,int y3,int x4,int y4);
void UI()
{
	setbkcolor(RGB(253, 241, 225));
	cleardevice();
	srand((unsigned)time(NULL));
	for (i = 1; i < ROWS-1; i++)
	{
		for (j = 1; j < COLS-1; j++)
		{
			arr[i][j] = rand() % 8 + 1;
		}
	}
	loadimage(&image0, _T("pic\\0.jpg"), 40, 40);
	loadimage(&image1, _T("pic\\1.jpg"), 40, 40);
	loadimage(&image2, _T("pic\\2.jpg"), 40, 40);
	loadimage(&image3, _T("pic\\3.jpg"), 40, 40);
	loadimage(&image4, _T("pic\\4.jpg"), 40, 40);
	loadimage(&image5, _T("pic\\5.jpg"), 40, 40);
	loadimage(&image6, _T("pic\\6.jpg"), 40, 40);
	loadimage(&image7, _T("pic\\7.jpg"), 40, 40);
	loadimage(&image8, _T("pic\\8.jpg"), 40, 40);
	loadimage(&image9, _T("pic\\9.jpg"), 40, 40);
	loadimage(&image10, _T("pic\\10.jpg"), 40, 40);
	for (i = 1; i <ROWS-1; i++)
	{
		for (j = 1; j < COLS-1; j++)
		{
			if (arr[i][j] == 0)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image0);
			if (arr[i][j] == 1)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image1);
			if (arr[i][j] == 2)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image2);
			if (arr[i][j] == 3)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image3);
			if (arr[i][j] == 4)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image4);
			if (arr[i][j] == 5)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image5);
			if (arr[i][j] == 6)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image6);
			if (arr[i][j] == 7)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image7);
			if (arr[i][j] == 8)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image8);
			if (arr[i][j] == 9)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image9);
			if (arr[i][j] == 10)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image10);
		}
	}

}
void contralGame()
{
	char c = 0;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			for (i = 0; i < ROWS; i++)
			{
				for (j = 0; j < COLS; j++)
				{
					if (m.x - 40 >= 44 * j&&m.x - 40 <= 40 * (j + 1) + 4 * j)
					{
						if (m.y - 80 >= 44 * i&&m.y - 80 <= 40 * (i + 1) + 4 * i)
						{
							judge();
							if (x == 0 && arr[i][j]<100)
							{
								x1 = i;
								y1 = j;
								arr[i][j] += 100;
							}
							if (x == 1 && arr[i][j]<100)
							{
								x2 = i;
								y2 = j;
								arr[i][j] += 100;
								storeLocation(x1,y1,x2,y2);
								judge2();
							}
							printimage();
						}
					}
				}
			}
		}
	}
}
void judge()
{
	x = 0;
	for (k =1; k < ROWS-1; k++)
	{
		for (l = 1; l< COLS-1; l++)
		{
			if (arr[k][l] >= 100)
				x++;
		}
	}
}
void storeLocation(int x1,int y1,int x2,int y2)
{
	for (l = 0; l < 25; l++)
	{
		arr1[0][l] = -1;
		arr1[1][l] = -1;
		arr2[0][l] = -1;
		arr2[1][l] = -1;
	}
	if (arr[x1][y1] == arr[x2][y2])
	{
		for (l = x1 + 1; l < 15; l++)
		{
			if (arr[l][y1] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr1[0][k] == -1)
					{
						arr1[0][k] = l;
						arr1[1][k] = y1;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = x1 - 1; l >= 0; l--)
		{
			if (arr[l][y1] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr1[0][k] == -1)
					{
						arr1[0][k] = l;
						arr1[1][k] = y1;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = y1 - 1; l >= 0; l--)
		{
			if (arr[x1][l] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr1[0][k] == -1)
					{
						arr1[1][k] = l;
						arr1[0][k] = x1;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = y1 + 1; l < 12; l++)
		{
			if (arr[x1][l] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr1[0][k] == -1)
					{
						arr1[1][k] = l;
						arr1[0][k] = x1;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = x2 + 1; l < 15; l++)
		{
			if (arr[l][y2] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr2[0][k] == -1)
					{
						arr2[0][k] = l;
						arr2[1][k] = y2;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = x2 - 1; l >= 0; l--)
		{
			if (arr[l][y2] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr2[0][k] == -1)
					{
						arr2[0][k] = l;
						arr2[1][k] = y2;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = y2 - 1; l >= 0; l--)
		{
			if (arr[x2][l] == 0)
			{
				for (k = 0; k < 25; k++)
				{
					if (arr2[0][k] == -1)
					{
						arr2[1][k] = l;
						arr2[0][k] = x2;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		for (l = y2 + 1; l < 12; l++)
		{
			if (arr[x2][l] == 0)
			{
				for (k = 0; k< 25; k++)
				{
					if (arr2[0][k] == -1)
					{
						arr2[1][k] = l;
						arr2[0][k] = x2;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
}
void judge2()
{
	int s = 0;
	flag = 0;
	if (arr[x1][y1] == arr[x2][y2])
	{
		for (k = 0; k < 25; k++)//无拐点和一个拐点
		{
			for (l = 0; l < 25; l++)
			{
				if (arr1[0][k] == arr2[0][l] && arr1[1][k] == arr2[1][l] && arr1[0][k] != -1 && arr2[0][k] != -1)//判断是否有相交的位置
				{
					arr[x1][y1] = 0;
					arr[x2][y2] = 0;
				}
				else if (x1 == x2 && (y1 - y2 == 1 || y1 - y2 == -1))//判断是否横向相邻
				{
					arr[x1][y1] = 0;
					arr[x2][y2] = 0;
				}
				else if (y1 == y2 && (x1 - x2 == 1 || x1 - x2 == -1))//判断是否纵向相邻
				{
					arr[x1][y1] = 0;
					arr[x2][y2] = 0;
				}
				else
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)//两个拐点
		{
			for (l = 0; l < 25; l++)//横向扫描
			{
				if (arr1[0][l] == x1)
				{
					for (k = 0; k < 25; k++)
					{
						if (arr1[1][l] == arr2[1][k])
						{

							judge3(x3,y3,x4,y4);
							s = 1;
							break;
						}
					}
				}
				if (s == 1)
					break;
			}
			if (s == 0)
			{
				for (l = 0; l < 25; l++)
				{
					if (arr1[1][l] == y1)
					{
						for (k = 0; k < 25; k++)
						{
							if (arr1[0][l] == arr2[0][k])
							{
								judge3(x3, y3, x4, y4);
								s = 1;
								break;
							}
						}
					}
					if (s == 1)
						break;
				}
			}
		}
	}
	for (k = 0; k < 15; k++)
	{
		for (l = 0; l < 15; l++)
		{
			arr[k][l] = arr[k][l] % 100;
		}
	}
}
void printimage()
{
	for (i = 0; i <ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 0)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image0);
			if (arr[i][j] == 1)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image1);
			if (arr[i][j] == 2)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image2);
			if (arr[i][j] == 3)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image3);
			if (arr[i][j] == 4)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image4);
			if (arr[i][j] == 5)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image5);
			if (arr[i][j] == 6)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image6);
			if (arr[i][j] == 7)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image7);
			if (arr[i][j] == 8)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image8);
			if (arr[i][j] == 9)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image9);
			if (arr[i][j] == 10)
				putimage(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, &image10);
			if (arr[i][j] > 100)
			{
				setcolor(RED);
				rectangle(4 * j + 40 * (j + 1), 4 * i + 40 * (i + 1) + 40, 4 * j + 40 * (j + 2)-1, 4 * i + 40 * (i + 2) + 40-1);
			}
		}
	}
}
void judge3(int x3,int y3,int x4,int y4)
{
	storeLocation(x3, y3, x4, y4);
	for (k = 0; k < 25; k++)
	{
		for (l = 0; l < 25; l++)
		{
			if (arr1[0][k] == arr2[0][l] && arr1[1][k] == arr2[1][l] && arr1[0][k] != -1 && arr2[0][k] != -1)
			{
				arr[x1][y1] = 0;
				arr[x2][y2] = 0;
			}
			else if (x3 == x4 && (y3 - y4 == 1 || y3 - y4 == -1))
			{
				arr[x1][y1] = 0;
				arr[x2][y2] = 0;
			}
			else if (y3 == y4 && (x3 - x4 == 1 || x3 - x4 == -1))
			{
				arr[x1][y1] = 0;
				arr[x2][y2] = 0;
			}
		}
	}
}
int main(void)
{
	initgraph(600, 780);
	UI();
	contralGame();
	getch();
	closegraph();
	return 0;
}