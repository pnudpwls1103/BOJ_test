#include <iostream>
#include <deque>
#include <tuple>
#define X 0
#define Y 1
#define D 2
using namespace std;

int n, m, r, c, d, answer;
int board[55][55];
int vis[55][55];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void input() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}

void solution() {
	answer = 0;
	deque<tuple<int, int, int> > q;
	vis[r][c] = 1;
	q.push_back({ r, c , d });
	answer++;
	
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop_front();
		int x = get<X>(cur);
		int y = get<Y>(cur);
		int dir = get<D>(cur);
		
		int cnt, nd = dir;
		for (cnt = 0; cnt < 4; cnt++) {
			nd = (dir + 3) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];

			if (vis[nx][ny] || board[nx][ny] == 1) {
				dir = nd;
				continue;
			}

			vis[nx][ny] = 1;
			q.push_back({ nx, ny, nd });
			answer++;
			break;
		}
		
		if (cnt == 4) {
			int nx = x - dx[dir];
			int ny = y - dy[dir];

			if (board[nx][ny] == 1) continue;

			q.push_back({ nx, ny, dir });
		}
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
	cout << answer << '\n';
}