#include <bits/stdc++.h>
using namespace std;
#define X 0
#define Y 1
#define Z 2
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

// 꼭 3차원으로 해야할까?
int m, n, h;
int tomato[100][100][100];
int dist[100][100][100];

int main() {
	cin >> m >> n >> h;
	
	for(int k = 0; k < h; k++) {
		for(int i = 0; i < n ; i++) {
			for(int j = 0; j < m; j++) {
				cin >> tomato[k][i][j];
			}
		}
	}
	
	queue<tuple<int, int, int>> Q;
	for(int k = 0; k < h; k++) {
		for(int i = 0; i < n ; i++) {
			for(int j = 0; j < m; j++) {
				if(tomato[k][i][j] == 1)
					Q.push({i, j , k});	
				if(tomato[k][i][j] == 0)
					dist[k][i][j] = -1;
			}
		}
	}
	
	while(!Q.empty()) {
		tuple<int, int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 6; dir++) {
			int nx = get<X>(cur) + dx[dir];
			int ny = get<Y>(cur) + dy[dir];
			int nz = get<Z>(cur) + dz[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if(dist[nz][nx][ny] >= 0) continue;
			
			dist[nz][nx][ny] = dist[get<Z>(cur)][get<X>(cur)][get<Y>(cur)] + 1;
			Q.push({nx, ny, nz});
		}
	}
	
	int days = 0;
	for(int k = 0; k < h; k++) {
		for(int i = 0; i < n ; i++) {
			for(int j = 0; j < m; j++) {
				if(tomato[k][i][j] == 0 && dist[k][i][j] < 0) {
					cout << -1;
					return 0;
				}
				
				days = max(days, dist[k][i][j]);
			}
		}
	}
	
	cout << days;
}