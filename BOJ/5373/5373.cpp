// https://www.acmicpc.net/problem/5373
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

// 0 = white, up
// 1 = yellow, down
// 2 = red, front
// 3 = orange, back
// 4 = green, left
// 5 = blue, right
const char CUBE[6][3][3] = {
  {
    'w','w','w',
    'w','w','w',
    'w','w','w',
  },
  {
    'y','y','y',
    'y','y','y',
    'y','y','y',
  },
  {
    'r','r','r',
    'r','r','r',
    'r','r','r',
  },
  {
    'o','o','o',
    'o','o','o',
    'o','o','o',
  },
  {
    'g','g','g',
    'g','g','g',
    'g','g','g',
  },
  {
    'b','b','b',
    'b','b','b',
    'b','b','b',
  },
};
char cube[6][3][3];

void cclockWise(const int &s) {
  int temp[3][3];

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      temp[2-j][i] = cube[s][i][j];
    }
  }

  std::copy(&temp[0][0], &temp[2][3], &cube[s][0][0]);  
}
void clockWise(const int &s) {
  int temp[3][3];

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      temp[j][2-i] = cube[s][i][j];
    }
  }

  std::copy(&temp[0][0], &temp[2][3], &cube[s][0][0]);  
}
// - ccw
// + cw
void up(const char &d) {
  char temp[3];
  switch(d) {
    case '+':
      clockWise(0);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[2][0][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][0][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][0][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][0][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][0][i]);
      }
      break;
    case '-':
      cclockWise(0);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[2][0][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][0][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][0][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][0][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][0][i]);
      }
      break;
  }
}
void down(const char &d) {
  char temp[3];
  switch(d) {
    case '-':
      clockWise(1);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[2][2][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][2][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][2][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][2][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][2][i]);
      }
      break;
    case '+':
      cclockWise(1);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[2][2][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][2][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][2][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][2][i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][2][i]);
      }
      break;
  }
}
void front(const char &d) {
  char temp[3];
  switch(d) {
    case '+':
      clockWise(2);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[0][2][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][2][2-i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][2-i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][2][i]);
      }
      break;
    case '-':
      cclockWise(2);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[0][2][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][2-i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][2][2-i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][2][i]);
      }
      break;
  }
}
void back(const char &d) {
  char temp[3];
  switch(d) {
    case '+':
      clockWise(3);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[0][0][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][2-i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][0][2-i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][0][i]);
      }
      break;
    case '-':
      cclockWise(3);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[0][0][i];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[5][i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][0][2-i]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[4][2-i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][0][i]);
      }
      break;
  }
}
void left(const char &d) {
  char temp[3];
  switch(d) {
    case '+':
      clockWise(4);
      for (int i = 0; i < 3; ++i) 
        temp[i] = cube[0][i][0];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][2-i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][2-i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][i][0]);
      }
      break;
    case '-':
      cclockWise(4);
      for (int i = 0; i < 3; ++i) 
        temp[i] = cube[0][i][0];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][2-i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][2-i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][i][0]);
      }
      break;
  }
}
void right(const char &d) {
  char temp[3];
  switch(d) {
    case '+':
      clockWise(5);
      for (int i = 0; i < 3; ++i) 
        temp[i] = cube[0][i][2];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][2-i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][2-i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][i][2]);
      }
      break;
    case '-':
      cclockWise(5);
      for (int i = 0; i < 3; ++i)
        temp[i] = cube[0][i][2];
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[2][i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[1][2-i][2]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[3][2-i][0]);
      }
      for (int i = 0; i < 3; ++i) {
        std::swap(temp[i], cube[0][i][2]);
      }
      break;
  }
}

void run(const char &s, const char &d) {
  switch(s) {
    case 'U':
      up(d);
      break;
    case 'D':
      down(d);
      break;
    case 'F':
      front(d);
      break;
    case 'B':
      back(d);
      break;
    case 'L':
      left(d);
      break;
    case 'R':
      right(d);
      break;
  }
}

void printAns() {
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) {
      cout << cube[0][y][x];
    }
    cout << '\n';
  }
}
void print() {
  cout << "===================\n";
  for (int i = 0; i < 6; ++i) {
    for (int y = 0; y < 3; ++y) {
      for (int x = 0; x < 3; ++x) {
        cout << cube[i][y][x];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  cout <<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int t; cin >> t;
  while (t--) {
    std::copy(&CUBE[0][0][0], &CUBE[5][2][3], &cube[0][0][0]);
    
    int iter; cin >> iter;
    for (int i = 0; i < iter; ++i) {
      char s, d; cin >> s >> d;
      run(s,d);
    }
    printAns();
  }
}
// g++ -o a -std=c++17 *.cpp