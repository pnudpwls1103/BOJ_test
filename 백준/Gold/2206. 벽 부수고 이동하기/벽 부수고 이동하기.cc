#include <bits/stdc++.h>
using namespace std;
#define X 0
#define Y 1
#define B 2

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
string maps[1000];
int dist[1000][1000][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	  cin >> maps[i];
	
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	dist[0][0][0] = dist[0][0][1] = 1;
	
	queue<tuple<int, int, int>> Q;
	Q.push({0, 0, 0});
	
	while(!Q.empty()) {
		tuple<int, int, int> cur = Q.front(); Q.pop();
		int x = get<X>(cur);
		int y = get<Y>(cur);
		int broken = get<B>(cur);
		if(x == n-1 && y == m-1) {
			cout << dist[x][y][broken];
			return 0;
		}
			
		int nextdist = dist[x][y][broken] + 1;
		for(int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(maps[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = nextdist;
				Q.push({nx, ny, broken});
			}
			
			if(broken == 0 && maps[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = nextdist;
				Q.push({nx, ny, 1});
			}
		}
	}
	
	cout << -1;
	return 0;
} 