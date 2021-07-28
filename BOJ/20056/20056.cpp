// https://www.acmicpc.net/problem/20056
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using fireball = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[8][2] = {
	{-1, 0},
	{-1, 1},
	{ 0, 1},
	{ 1, 1},
	{ 1, 0},
	{ 1,-1},
	{ 0,-1},
	{-1,-1}
};

int n,m,k;
std::vector<fireball> v[51][51];

// merge fireball
void merge()
{
	for(int r = 1; r <= n; ++r)
	{
		for(int c = 1; c <= n; ++c)
		{
			int size = v[r][c].size();
			if(size >= 2)
			{
				int W=0, S=0, D=0;
				for(const auto &fb: v[r][c])
				{
					int w,s,d;
					std::tie(w,s,d) = fb;

					W += w;
					S += s;
					D += d%2;
				}
				v[r][c].clear();
				W /= 5; S /= size;
				if(W == 0) continue;

				int i;
				if(D == 0 || D == size) i = 0;
				else i = 1;
				
				for(i; i < 8; i+=2)
					v[r][c].push_back({W,S,i});
			}
		}
	}
}

// move fireball
void move()
{
	std::vector<fireball> temp[51][51];

	for(int r = 1; r <= n; ++r)
	{
		for(int c = 1; c <= n; ++c)
		{
			for(const auto &fb: v[r][c])
			{
				int w,s,d;
				std::tie(w,s,d) = fb;

				int nr = r+DIR[d][0]*s;
				int nc = c+DIR[d][1]*s;

				nr = (nr < 0) ? n+(nr%n) : (nr%n);
				nc = (nc < 0) ? n+(nc%n) : (nc%n);

				nr = (nr == 0) ? n : nr;
				nc = (nc == 0) ? n : nc;
				
				temp[nr][nc].push_back({w,s,d});
			}
			v[r][c].clear();
		}
	}
	std::copy(&temp[0][0], &temp[50][51], &v[0][0]);
	merge();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 0; i < m; ++i)
	{
		int r,c,w,s,d;
		cin >> r >> c >> w >> s >> d;
		v[r][c].push_back({w,s,d});
	}

	while(k--)
		move();
	
	int sum = 0;
	for(int r = 1; r <= n; ++r)
	{
		for(int c = 1; c <= n; ++c)
		{
			for(const auto &fb: v[r][c])
				sum += std::get<0>(fb);
		}
	}

	cout << sum << '\n';
}//g++ -o a -std=c++17 *.cpp