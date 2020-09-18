// https://www.acmicpc.net/problem/18258
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,x; cin >> n;
	std::queue<int> q;
	std::string temp;
	while(n--) {
		cin >> temp;
		if(temp == "push") {
			cin >> x;
			q.push(x);
		}
		else if(temp == "pop") {
			if(true == q.empty()) cout << -1;
			else {
				cout << q.front();
				q.pop();
			}
			cout << '\n';
		}
		else if(temp == "size") {
			cout << q.size() << '\n';
		}
		else if(temp == "empty") {
			if(true == q.empty()) cout << 1;
			else cout << 0;
			cout << '\n';
		}
		else if(temp == "front") {
			if(true == q.empty()) cout << -1;
			else cout << q.front();
			cout << '\n';
		}
		else if(temp == "back") {
			if(true == q.empty()) cout << -1;
			else cout << q.back();
			cout << '\n';
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;