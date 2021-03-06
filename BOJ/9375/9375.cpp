#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	unsigned int sum = 1;

	string temp, input;
	vector<string> sv;
	vector<int> cnt;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> temp >> input;
			ptrdiff_t pos = distance(sv.begin(), find(sv.begin(), sv.end(), input));
			if (pos >= sv.size())
			{
				sv.push_back(input);
				cnt.push_back(1);
			}
			else
				cnt.at(pos)++;
		}

		for (int i = 0; i < cnt.size(); ++i)
			sum *= (cnt[i]+1);
		cout << sum - 1 << endl;
		
		sv.clear(); cnt.clear(); sum = 1;
	}
}