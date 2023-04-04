#include <iostream>
#include <cstring>
#include <deque>
#define X first
#define Y second
using namespace std;

int n, m, k, answer;
int board[25][25];
int vis[25][25];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int dir = 0;

int dice[4][3] = {
	{-1, 2, -1},
	{ 4, 1, 3 },
	{-1, 5, -1},
	{-1, 6, -1}
};

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}

void getScore(int i, int j) {
	for (int i = 0; i < n; i++)
		memset(vis[i], 0, sizeof(vis[i]));

	int num = board[i][j];
	int cnt = 1;

	deque<pair<int, int> > q;
	q.push_back({ i, j });
	vis[i][j] = 1;

	pair<int, int> cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != num) continue;

			vis[nx][ny] = 1;
			cnt++;
			q.push_back({ nx, ny });
		}
	}

	answer += (num * cnt);
}

void updateDice(int dir) {
	int d1 = dice[0][1];
	int d2 = dice[1][0];
	int d3 = dice[1][1];
	int d4 = dice[1][2];
	int d5 = dice[2][1];
	int d6 = dice[3][1];
	switch (dir) {
	case 0:
		dice[1][0] = d6;
		dice[1][1] = d2;
		dice[1][2] = d3;
		dice[3][1] = d4;
		break;
	case 1:
		dice[0][1] = d3;
		dice[1][1] = d5;
		dice[2][1] = d6;
		dice[3][1] = d1;
		break;
	case 2:
		dice[1][0] = d3;
		dice[1][1] = d4;
		dice[1][2] = d6;
		dice[3][1] = d2;
		break;
	case 3:
		dice[0][1] = d6;
		dice[1][1] = d1;
		dice[2][1] = d3;
		dice[3][1] = d5;
		break;
	}
}

int rotateDir(int a, int b) {
	int rotation = 0;
	if (a > b) rotation = -1;
	else if (a < b) rotation = 1;

	return rotation;
}

int reverseDir(int dir) {
	int result = dir;
	switch (dir) {
	case 0:
		result = 2;
		break;
	case 1:
		result = 3;
		break;
	case 2:
		result = 0;
		break;
	case 3:
		result = 1;
		break;
	}

	return result;
}

void solution() {
	int x = 0;
	int y = 0;
	for (int i = 0; i < k; i++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			dir = reverseDir(dir);
			nx = x + dx[dir];
			ny = y + dy[dir];
		}

		getScore(nx, ny);
		updateDice(dir);
		
		int rotation = rotateDir(dice[3][1], board[nx][ny]);
		if ((dir + rotation) < 0)
			dir = 4;

		dir = (dir + rotation) % 4;
		x = nx;
		y = ny;
	}

	cout << answer << '\n';
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}

