#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int tomato[1000][1000];
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> tomato[i][j];
		}
	}
	
	int days = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(tomato[i][j] == 1)
				Q.push({i, j});
		}
	}
	
	while(!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		if(days < tomato[cur.X][cur.Y]) days = tomato[cur.X][cur.Y];

		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(tomato[nx][ny] != 0) continue;
			
			tomato[nx][ny] = tomato[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
			
			if(days < tomato[nx][ny]) days = tomato[nx][ny];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(tomato[i][j] == 0) {
				cout << -1;
				return 0;	
			}
		}
	}
	
	cout << days-1;
}