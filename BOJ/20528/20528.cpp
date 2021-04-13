// https://www.acmicpc.net/problem/20528
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    bool flag = true;
    std::string str; cin >> str;
    char ch = str[0];
    for(int i = 1; i < n; ++i)
    {
        cin >> str;
        if(str[0] != ch) flag = false;
    }
    if(true == flag) cout << 1;
    else cout << 0;
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp