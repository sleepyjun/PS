// https://www.acmicpc.net/problem/3003
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

enum CHESS {KING = 1, QUEEN = 1, ROOK = 2,
		   BISHOP = 2, KNIGHT = 2, PAWN = 8};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int king, queen, rook, bishop, knight, pawn;
	cin >> king >> queen >> rook
		>> bishop >> knight >> pawn;
	
	cout << CHESS::KING - king << ' '
		 << CHESS::QUEEN - queen << ' '
		 << CHESS::ROOK - rook << ' '
		 << CHESS::BISHOP - bishop << ' '
		 << CHESS::KNIGHT - knight << ' '
		 << CHESS::PAWN - pawn
		 << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;