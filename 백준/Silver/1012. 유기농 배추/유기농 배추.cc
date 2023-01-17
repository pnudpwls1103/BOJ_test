#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ground[50][50];
int vis[50][50];

int t, m, n, k;
int x, y;

// 시작점이 여러개인 BFS 유형
int BFS() {
	queue<pair<int, int>> Q;
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] || ground[i][j] != 1) continue;
			vis[i][j] = 1;
			Q.push({i, j});
			cnt++;
			
			while(!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(vis[nx][ny] || ground[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	
	return cnt;
}

int main() {
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for(int j = 0; j < n; j++) {
			fill(ground[j], ground[j]+m, 0);
			fill(vis[j], vis[j]+m, 0);
		}
		for(int j = 0; j < k; j++) {
			cin >> x >> y;
			ground[y][x] = 1;
		}

		cout << BFS() << '\n';
	}
}