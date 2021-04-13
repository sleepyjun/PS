// // Solution to Keys
// // Author: Thomas Beuman

// // Time complexity: O(26*h*w)
// // Memory: O(h*w)

// // @EXPECTED_RESULTS@: CORRECT

// // Solution method: Breadth-first search
// //   Whenever a new key is found, clear BFS queue


// #include <cstdio>
// #include <queue>
// #include <utility>
// #include <cstring>
// using namespace std;


// char Map[102][102];
// bool GotKey[26];

// queue<pair<int,int> > BFSqueue;
// bool Visited[102][102];
// int dx[4] = {0,0,-1,1};
// int dy[4] = {-1,1,0,0};


// int main()
// { int cases, casenr, h, w, x, y, x2, y2, i, docs;
//   pair<int,int> P;
//   char keys[27], c;

//   scanf("%d\n", &cases);
//   for (casenr = 1; casenr <= cases; casenr++)
//   { 
//     // Read input
//     scanf("%d %d\n", &h, &w);
//     for (y = 1; y <= h; y++)
//       scanf("%s\n", Map[y]+1);
//     scanf("%s\n", keys);

//     // Add a layer of free space around the border of the map
//     h += 2;
//     w += 2;
//     for (x = 0; x < w; x++)
//       Map[0][x] = Map[h-1][x] = '.';
//     for (y = 0; y < h; y++)
//       Map[y][0] = Map[y][w-1] = '.';

//     // Determine keys in possession
//     memset(GotKey, false, sizeof(GotKey));
//     if (keys[0] != '0')
//       for (i = 0; keys[i] != '\0'; i++)
//         GotKey[keys[i]-'a'] = true;

//     // Initialize
//     BFSqueue = queue<pair<int,int> >();
//     memset(Visited, false, sizeof(Visited));
//     BFSqueue.push(make_pair(0,0));
//     Visited[0][0] = true;
//     docs = 0;

//     while (!BFSqueue.empty())
//     { P = BFSqueue.front();
//       BFSqueue.pop();
//       x = P.first;
//       y = P.second;
      
//       // Try all directions
//       for (i = 0; i < 4; i++)
//       { x2 = x + dx[i];
//         y2 = y + dy[i];

//         // Check if the new location is on the map and unseen
//         if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h && !Visited[y2][x2])
//         { Visited[y2][x2] = true;
//           c = Map[y2][x2];

//           // If it's a new key: clear BFS queue
//           if (c >= 'a' && c <= 'z' && !GotKey[c-'a'])
//           { GotKey[c-'a'] = true;
//             // Reinitialize
//             BFSqueue = queue<pair<int,int> >();
//             memset(Visited, false, sizeof(Visited));
//             BFSqueue.push(make_pair(x2,y2));
//             Visited[y2][x2] = true;
//             break;
//           }

//           if (c == '$')
//           { docs++;
//             Map[y2][x2] = '.'; // Prevent counting multiple times
//           }

//           // If not a wall or an unopenable door, add to BFS queue
//           if (c != '*' && !(c >= 'A' && c <= 'Z' && !GotKey[c-'A']))
//             BFSqueue.push(make_pair(x2,y2));
//         }
//       }
//     }
//     printf("%d\n", docs);
//   }
//   return 0;
// }

// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
char map[105][105];
bool visited[105][105];
int Y,X; 
bool position(int y, int x)
{
	if(y < 0 || y > Y+1 || x < 0 || x > X+1) return false;
	if(visited[y][x] == true) return false;
	if(map[y][x] == '*') return false;
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&map[0][0], &map[104][105], '.');
		std::fill(&visited[0][0], &visited[104][105], false);
		
		cin >> Y >> X;
		for(int i = 1; i <= Y; ++i)
			for(int j = 1; j <= X; ++j)
				cin >> map[i][j];
		
		int key = 0;
		std::string keys; cin >> keys;
		if(keys != "0") for(const char &k : keys) key |= (1<<(k-'a'));
		
		int cnt = 0;
		std::queue<pii> q;
		q.push({0,0}); visited[0][0] = true;

		while(!q.empty())
		{
			const auto &curr = q.front();
			int cy = curr.first;
			int cx = curr.second;
			q.pop();
			for(int i = 0; i < 4; ++i)
			{
				int ny = cy+DIR[i][0];
				int nx = cx+DIR[i][1];
				if(false == position(ny,nx)) continue;
				visited[ny][nx] = true;

				if('a' <= map[ny][nx] && map[ny][nx] <= 'z')
				{
					key |= (1<<(map[ny][nx]-'a'));
					map[ny][nx] = '.';
					std::fill(&visited[0][0], &visited[104][105], false);
					visited[ny][nx] = true;
					q = std::queue<pii>();
					q.push({ny,nx});
					break;
				}
				else if('A' <= map[ny][nx] && map[ny][nx] <= 'Z')
				{
					if(key & (1<<(map[ny][nx]-'A'))) q.push({ny,nx});
				}
				else if(map[ny][nx] == '$')
				{
					q.push({ny,nx});
					map[ny][nx] = '.';
					cnt++;
				}
				else if(map[ny][nx] == '.')
					q.push({ny,nx});
				
			}
		}
		cout << cnt << '\n';
	}	
}//g++ -o a -std=c++11 *.cpp