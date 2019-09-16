#include <iostream>
#include <algorithm>

const int MAX = 16;
const int INF = 99999;
const bool LINKED[10][MAX] = {
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

void push(int arr[], int sw)
{
	for(int i = 0; i < MAX; ++i)
	{
		if(LINKED[sw][i] == true)
		{
			arr[i] += 3;
			if(arr[i] == 15) arr[i] = 3;
		}
	}
}
bool check(int arr[])
{
	bool flag = true;
	for(int i = 0; i < MAX && flag; ++i)
		if(arr[i] != 12) flag = false;
	return flag;
}
int func(int arr[], int sw)
{
	if(sw == 10) return (check(arr) ? 0 : INF);

	int res = INF;
	for(int i = 0; i < 4; ++i)
	{
		res = std::min(res, i + func(arr,sw+1));
		push(arr,sw);
	}
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int arr[MAX];
	int t; std::cin >> t;
	while(t--)
	{
		for(int i = 0; i < MAX; ++i)
			std::cin >> arr[i];
		int res = func(arr,0);
		std::cout << (res == INF ? -1 : res) << '\n';
	}
}