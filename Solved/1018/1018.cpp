#include<stdio.h>

#define MIN(x,y) ((x)<(y))?(x):(y)
int arr[51][51];
int black[8][8];
int white[8][8];

void start()
{
	int i,j;
	for(i=0;i<8;++i)
		for (j = 0; j < 8; ++j)
		{
			black[i][j] = (i + j) % 2 ? 1 : 0;
			white[i][j] = (i + j) % 2 ? 0 : 1;
		}
}
//black = 0 white = 1;
int main()
{
	int i, j;
	int x, y;
	int M, N;
	int wc, bc;
	int min = 80;
	char temp;
	scanf("%d %d", &M, &N);
	start();
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			getchar();
			scanf("%c", temp);
			arr[i][j] = temp == 'W' ? 1 : 0;
		}

	for (x = 0; x < M - 7; ++x)//가로
		for (y = 0; y < N - 7; ++y)//세로
		{
			wc = 0; bc = 0;
			for (i = x; i < x + 8; ++i)
				for (j = y; j < y + 8; ++j)
				{
					if (white[i-x][j-y] != arr[i][j])
						wc++;
					if (black[i-x][j-y] != arr[i][j])
						bc++;
				}
			min = MIN(min, MIN(wc, bc));
		}
	printf("%d", min);
	return 0;
}