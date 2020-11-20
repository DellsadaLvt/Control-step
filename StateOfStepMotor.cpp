// StateOfStepMotor.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

int i, j, k, m, dem=0;
int tt[25];

void ThuTuChan();
int State(int Pin);
void xuat_mang(void);

int main()
{
	ThuTuChan();
	printf("\n");
	printf("mang trang thai la: ");
	xuat_mang();
	return 0;
}


void ThuTuChan()
{
	printf("Hello World \n");
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (j == i)
				continue;
			else
			for (k = 1; k <= 4; k++)
			{
				if (k == j || k == i)
					continue;
				else
				for (m = 1; m <= 4; m++)
				{
					if (m == i || m == j || m == k)
						continue;
					else
					{
						printf("So thu %d:   %d%d%d%d \n", dem, i, j, k, m);
						tt[dem] = i*1000 + j*100 +k*10 +m;
						dem++;
						printf("state 1:0x0%d \n", State(i));
						printf("state 1:0x0%d \n", State(j));
						printf("state 1:0x0%d \n", State(k));
						printf("state 1:0x0%d \n", State(m));
						printf("***************************\n");
						printf("\n");
					}
				}
			}
		}
	}
}

int State(int Pin)
{
	int resuft;
	int state[5] = { 0, 1, 2, 4, 8 };
	return(resuft = state[Pin]);
}

void xuat_mang(void)
{
	for (i = 0; i < 24; i++)
	{
		printf("%4.0d, ", tt[i]);
	}
}