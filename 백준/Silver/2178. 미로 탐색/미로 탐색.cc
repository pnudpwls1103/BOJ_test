#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int board[100][100];
int vis[100][100];
int dis[100][100];
queue<pair<int, int>> Q;

int main() {
	cin >> n >> m;
	
	string tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		for(int j = 0; j < m; j++) {
			board[i][j] = tmp[j] - '0';
		}
	}
	
	vis[0][0] = 1;
	dis[0][0] = 1;
	Q.push({0, 0});
	
	while(!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny] || board[nx][ny] != 1) continue;
			
			vis[nx][ny] = 1;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			
			Q.push({nx, ny});
		}
	}
	
	cout << dis[n-1][m-1];
}