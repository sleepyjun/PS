// https://www.acmicpc.net/problem/17281
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <numeric>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;
int init[51][10];
bool ground[4];

void go(int &turn)
{
	turn = (turn == 8 ? 0 : turn+1);
}
void go(int cond, int &score)
{
	for(int i = 3; i >= 1; --i)
	{
		if(ground[i] && i+cond > 3)
		{
			score++;
		}
		else if(ground[i] && i+cond <= 3)
		{
			ground[i+cond] = true;
		}
		ground[i] = false;
	}
	if(cond == 4) score++;
	else ground[cond] = true;
}
int play(const std::vector<int> &seq)
{
	int score = 0;
	int turn = 0;
	for(int i = 0; i < n; ++i)
	{
		int outCount = 0;
		std::fill(ground, ground+4, false);

		while(1)
		{
			int hitter = seq[turn];
			int cond = init[i][hitter];
			if(cond == 0) outCount++;
			else go(cond, score);

			go(turn);
			if(outCount == 3) break;
		}
	}

	return score;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 9; ++j)
			cin >> init[i][j];

	std::vector<int> v(8);
	std::iota(v.begin(), v.end(), 1);

	int ans = -1;
	do {
		std::vector<int> seq(v.begin(), v.end());
		auto it = seq.begin();
		seq.insert(it+3, 0);

		ans = std::max(ans, play(seq));
	} while(std::next_permutation(v.begin(), v.end()));

	cout << ans << '\n';
}//g++ -o a -std=c++17 *.cpp