#include <iostream>

using namespace std;

int main()
{
   int x[3];
   int y[3];
   for(int i = 0; i < 3; ++i)
    cin >> x[i] >> y[i];
   if(((y[1] - y[0]) * (x[2] - x[0])) ==
      ((y[2] - y[0]) * (x[1] - x[0])))
        cout << "WHERE IS MY CHICKEN?";
   else
    cout << "WINNER WINNER CHICKEN DINNER!";
}
