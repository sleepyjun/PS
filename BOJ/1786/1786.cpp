#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 1000001;
int* fail_func(char* pat)
{
	int lengthP = strlen(pat);
	int* pi = new int[lengthP];
	pi[0] = -1;

	for(int j = 1; j < lengthP; ++j)
	{
		int i = pi[j-1];
		while((*(pat+j) != *(pat+i+1)) && (i>=0))
			i = pi[i];
		if(*(pat+j) == *(pat+i+1))
			pi[j] = i +1;
		else pi[j] = -1;
	}
	return pi;
}
int main()
{
	vector<int> result;
	char str[MAX] = {""};
	char pat[MAX] = {""};
	int *pi;
	int S, P, posP = 0;
	gets(str);
	gets(pat);

	S = strlen(str);
	P = strlen(pat);

	pi = fail_func(pat);

	for(int i = 0; i < S; ++i)
	{

		while(posP > 0 && str[i] != pat[posP])
			posP = pi[posP-1] + 1;

		if(pat[posP] == str[i])
		{
			if(posP == P - 1)
			{
				result.push_back(i - posP + 1);
				posP = pi[posP] + 1;
			}
			else
				posP++;
		}
		//else if(posP != 0) posP = pi[posP-1] + 1;
	}

	printf("%d\n",result.size());
	for(int i = 0; i < result.size(); ++i)
		printf("%d ", result[i]);
}
