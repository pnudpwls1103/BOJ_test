#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
string canvas[100];
int vis[100][100];

// type 0: 적록색약 X
// type 1: 적록색약 O
int BFS(char color, int type) {
	queue<pair<int, int>> Q;
	for(int i = 0; i < n; i++)
		fill(vis[i], vis[i]+n, 0);
	
	int area = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if((type == 0) && (vis[i][j] || canvas[i][j] != color)) continue;
			if((type == 1) && (vis[i][j] || canvas[i][j] == color)) continue;
			
			vis[i][j] = 1;
			Q.push({i, j});
			area++;
			
			while(!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if((type == 0) && (vis[nx][ny] || canvas[nx][ny] != color)) continue;
					if((type == 1) && (vis[nx][ny] || canvas[nx][ny] == color)) continue;
					
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	
	return area;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> canvas[i];
	}
	
	int r = BFS('R', 0); int g = BFS('G', 0); int b = BFS('B', 0);
	cout << r + g + b << ' ';
	cout << b + BFS('B', 1);
}