#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int canvas[500][500];
int vis[500][500];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int cnt;
int maxArea = 0;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> canvas[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] || canvas[i][j] != 1) continue;
			cnt++;
			vis[i][j] = 1;
			Q.push({i, j});

			int temp = 0;
			while(!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				//cout << cur.X << ", " << cur.Y << '\n';
				temp++;
				
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(vis[nx][ny] || canvas[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}

			if(maxArea < temp) maxArea = temp;
		}
	}
	
	cout << cnt << '\n' << maxArea;
}