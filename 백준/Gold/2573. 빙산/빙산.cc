#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int iceberg[300][300];
int vis[300][300];
int melt[300][300];

int GetSplitNum() {
	for(int i = 0; i < n; i++)
		fill(vis[i], vis[i]+m, 0);
	
	int cnt = 0;
	queue<pair<int, int>> Q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] || iceberg[i][j] == 0) continue;
			vis[i][j] = 1;
			Q.push({i, j});
			cnt++;
			
			while(!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(vis[nx][ny] || iceberg[nx][ny] == 0) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	
	return cnt;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> iceberg[i][j];
	
	queue<pair<int, int>> Q;
	
	int year = 0;
	while(true) {
		int num = GetSplitNum();
		if(num > 1) {
			cout << year;
			break;
		}
		if(num == 0) {
			cout << 0;
			break;
		}
		
		year++;
		for(int i = 0; i < n; i++) {
			fill(vis[i], vis[i]+m, 0);
			fill(melt[i], melt[i]+m, 0);
		}
			
		
		// 얼마나 녹아야 하는지 저장
		for(int i = 0; i < n ; i++) {
			for(int j = 0; j < m; j++) {
				if(vis[i][j] || iceberg[i][j] == 0) continue;
				vis[i][j] = 1;
				Q.push({i, j});
				
				while(!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for(int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						
						if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if(iceberg[nx][ny] == 0 && iceberg[cur.X][cur.Y] > 0) 
							melt[cur.X][cur.Y]++;
						if(vis[nx][ny] || iceberg[nx][ny] == 0) continue;
						
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
		
		// 한꺼번에 녹이기
		for(int i = 0; i < n ; i++) {
			for(int j = 0; j < m; j++) {
				if(iceberg[i][j] - melt[i][j] < 0) iceberg[i][j] = 0;
				else iceberg[i][j] -= melt[i][j];
			}
		}
	}
	
	return 0;
}