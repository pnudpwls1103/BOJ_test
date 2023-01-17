#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, l;
int x_1, y_1, x_2, y_2;
int dist[300][300];

void BFS() {
	queue<pair<int, int>> Q;
	
	for(int i = 0; i < l; i++)
		fill(dist[i], dist[i]+l, -1);
	
	dist[x_1][y_1] = 0;
	Q.push({x_1, y_1});
	
	while(!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
			if(dist[nx][ny] >= 0) continue;
			
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> l;
		cin >> x_1 >> y_1;
		cin >> x_2 >> y_2;
		
		BFS();
		
		cout << dist[x_2][y_2] << '\n';
	}
}