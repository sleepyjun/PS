// https://www.acmicpc.net/problem/16935
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> arr[101];
int n, m, r; 

void colSwap();
void rowSwap();
void clockWise();
void cclockWise();
void clockWiseGroup();
void cclockWiseGroup();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int x; cin >> x;
			arr[i].push_back(x);
		}
	}

	while(r--)
	{
		int cmd; cin >> cmd;

		switch(cmd) 
		{
		case 1: 
			colSwap();
			break;
		case 2:
			rowSwap();
			break;
		case 3:
			clockWise();
			break;
		case 4:
			cclockWise();
			break;
		case 5:
			clockWiseGroup();
			break;
		case 6:
			cclockWiseGroup();
			break;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}//g++ -o a -std=c++17 *.cpp


void colSwap()
{
	for(int i = 0; i < n/2; ++i)
	{
		int j = n-i-1;
		if(i!=j) std::swap(arr[i], arr[j]);
	}
}
void rowSwap()
{
	for(int i = 0; i < n; ++i)
		std::reverse(arr[i].begin(), arr[i].end());
}
void clockWise()
{
	std::vector<int> temp[m];

	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			temp[i].push_back(arr[j][i]);
	for(int i = 0; i < m; ++i)
		arr[i] = temp[i];

	std::swap(n,m);
	rowSwap();
}
void cclockWise()
{
	std::vector<int> temp[m];

	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			temp[i].push_back(arr[j][i]);
	for(int i = 0; i < m; ++i)
		arr[i] = temp[i];

	std::swap(n,m);
	colSwap();
}
void clockWiseGroup()
{
	int dn = n/2;
	int dm = m/2;
	std::vector<int> temp[n];

	for(int i = 0; i < dn; ++i)
		for(int j = 0; j < dm; ++j)
			temp[i].push_back(arr[i+dn][j]);
	
	for(int i = 0; i < dn; ++i)
		for(int j = dm; j < m; ++j)
			temp[i].push_back(arr[i][j-dm]);

	for(int i = dn; i < n; ++i)
		for(int j = 0; j < dm; ++j)
			temp[i].push_back(arr[i][j+dm]);

	for(int i = dn; i < n; ++i)
		for(int j = dm; j < m; ++j)
			temp[i].push_back(arr[i-dn][j]);

	for(int i = 0; i < n; ++i)
		arr[i] = temp[i];
}
void cclockWiseGroup()
{
	int dn = n/2;
	int dm = m/2;
	std::vector<int> temp[n];

	for(int i = 0; i < dn; ++i)
		for(int j = 0; j < dm; ++j)
			temp[i].push_back(arr[i][j+dm]);
	
	for(int i = 0; i < dn; ++i)
		for(int j = dm; j < m; ++j)
			temp[i].push_back(arr[i+dn][j]);

	for(int i = dn; i < n; ++i)
		for(int j = 0; j < dm; ++j)
			temp[i].push_back(arr[i-dn][j]);

	for(int i = dn; i < n; ++i)
		for(int j = dm; j < m; ++j)
			temp[i].push_back(arr[i][j-dm]);

	for(int i = 0; i < n; ++i)
		arr[i] = temp[i];
}