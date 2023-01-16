#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int r, c;
string miro[1000];
int dist[1000][1000];
int dist2[1000][1000]; // 지훈이 이동 시간

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		fill(dist[i], dist[i]+c, -1);
		fill(dist2[i], dist2[i]+c, -1);
	}
	
	queue<pair<int, int>> Q;
	char temp;
	pair<int, int> jihun;
	for(int i = 0; i < r; i++) {
		cin >> miro[i];
		for(int j = 0; j < c; j++) {
			temp = miro[i][j];
			if(temp == 'F') {
				dist[i][j] = 0;
				Q.push({i, j});
			}
			if(temp == 'J'){
				jihun = {i, j};
				dist2[i][j] = 0;
			}
				
		}
	}
	
	while(!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if(dist[nx][ny] >= 0 || miro[nx][ny] == '#') continue;
			
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}

	Q.push(jihun);
	
	int t = 1;
	while(!Q.empty()) {
		pair<int, int> cur = Q.front();
		t = dist2[cur.X][cur.Y];
		Q.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << t+1;
				return 0;
			}
			if(dist2[nx][ny] >= 0 || miro[nx][ny] == '#') continue;
			if(dist[nx][ny] >= 0 && dist[nx][ny] <= t+1) continue;
			
			dist2[nx][ny] = t+1;
			Q.push({nx, ny});
		}
	}
	
	cout << "IMPOSSIBLE";
}