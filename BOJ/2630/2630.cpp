#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>

#define WHITE 0
#define BLUE  1

int paper[129][129]; //1~128
int  nBule  = 0;
int  nWhite = 0;

void func(int x, int y, int N)
{
	if (N > 0)
	{
		//searching White paper
		bool bWhite = 1;
		for (int i = 0; i < N && bWhite; i++)
			for (int j = 0; j < N && bWhite; j++)
			{
				if (paper[y + i][x + j] != WHITE)
					bWhite = 0;
			}//(x~x+N-1, y~y+N-1)
		if (bWhite)
		{
			nWhite++;
			return;
		}

		//searching Blue paper
		bool bBlue = 1;
		for (int i = 0; i < N && bBlue; i++)
			for (int j = 0; j < N && bBlue; j++)
			{
				if (paper[y + i][x + j] != BLUE)
					bBlue = 0;
			}
		if (bBlue)
		{
			nBule++;
			return;
		}

		func(x, y, N / 2);					//AREA 1
		func(x + N / 2, y, N / 2);			//AREA 2
		func(x, y + N / 2, N / 2);			//AREA 3
		func(x + N / 2, y + N / 2, N / 2);	//AREA 4
	}

}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &paper[i][j]);
	func(1, 1, N);
	printf("%d\n%d", nWhite, nBule);
}