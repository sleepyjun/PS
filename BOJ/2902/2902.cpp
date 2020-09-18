#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  char str[101];
  gets(str);
  for(int i = 0; i < strlen(str); ++i)
    if('A' <= str[i] && str[i] <= 'Z')
        cout << str[i];
}
