#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const string END = "END";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string str;

	while(1)
	{
		str.clear();
		getline(cin, str);
		if(str.compare(END) == 0) break;
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}