#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int w, h;
string building[1000];
int dist1[1000][1000];	// 불 시간
int dist2[1000][1000];	// 상근 이동 시간

void BFS() {
	queue<pair<int, int>> Q1;	// 불
	queue<pair<int, int>> Q2;	// 상근
	
	for(int i = 0; i < h; i++) {
		fill(dist1[i], dist1[i]+w, -1);
		fill(dist2[i], dist2[i]+w, -1);
	}
	
	// 불
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(building[i][j] == '*') {
				dist1[i][j] = 0;
				Q1.push({i, j});
			}
			if(building[i][j] == '@') {
				dist2[i][j] = 0;
				Q2.push({i, j});
			}
		}
	}
	
	while(!Q1.empty()) {
		pair<int, int> cur = Q1.front(); Q1.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if(dist1[nx][ny] >= 0 || building[nx][ny] == '#') continue;
			
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({nx, ny});
		}
	}
	
	while(!Q2.empty()) {
		pair<int, int> cur = Q2.front(); Q2.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << dist2[cur.X][cur.Y] + 1 << '\n';
				return;
			}
			if(dist2[nx][ny] >= 0 || building[nx][ny] == '#') continue;
			if(dist1[nx][ny] >= 0 && dist2[cur.X][cur.Y]+1 >= dist1[nx][ny]) continue;
			
			 
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> w >> h;
		for(int j = 0; j < h; j++) {
			cin >> building[j];
		}
		
		BFS();
	}
}